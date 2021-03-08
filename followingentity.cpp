#include "followingentity.h"

#include <QPropertyAnimation>
#include <QTimer>

FollowingEntity::FollowingEntity(QString image, int x, int y, double speed, int maxHealth, MainController *value):
    LivingEntity(image, x, y, speed, maxHealth)
{
    mc = value;
    QTimer *moveTimer = new QTimer();
    move();
}

void FollowingEntity::move()
{
    int dir = nextMove();

    if(dir == U) moveUp();
    else if(dir == D) moveDown();
    else if(dir == R) moveRight();
    else if(dir == L) moveLeft();
}

void FollowingEntity::moveUp()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
    QObject::connect(animation, SIGNAL(finished()), this, SLOT(move()));
    animation->setDuration(1000/getSpeed());
    animation->setEndValue(y()-PIXELS);
    animation->start();
}

void FollowingEntity::moveDown()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "y");
    QObject::connect(animation, SIGNAL(finished()), this, SLOT(move()));
    animation->setDuration(1000/getSpeed());
    animation->setEndValue(y()+PIXELS);
    animation->start();
}

void FollowingEntity::moveLeft()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
    QObject::connect(animation, SIGNAL(finished()), this, SLOT(move()));
    animation->setDuration(1000/getSpeed());
    animation->setEndValue(x()-PIXELS);
    animation->start();
}

void FollowingEntity::moveRight()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "x");
    QObject::connect(animation, SIGNAL(finished()), this, SLOT(move()));
    animation->setDuration(1000/getSpeed());
    animation->setEndValue(x()+PIXELS);
    animation->start();
}

//////////TEST//////////

#include <utility>

struct noeud{
    float cout_g, cout_h, cout_f;
    std::pair<int,int> parent;    // 'adresse' du parent (qui sera toujours dans la map fermée)
};

struct point{
    int x,y;
};

typedef std::map< std::pair<int,int>, noeud> l_noeud;

l_noeud liste_fermee;
l_noeud liste_ouverte;

point arrivee;
noeud depart;

float distance(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

bool deja_present_dans_liste(std::pair<int,int> n, l_noeud& l){
    l_noeud::iterator i = l.find(n);
    if (i==l.end())
        return false;
    else
        return true;
}

void ajouter_cases_adjacentes(std::pair <int,int>& n, int ** collisionMap){
    noeud tmp;

    for (int i=n.first-1; i<=n.first+1; i++){
        if ((i<0) || (i>=20))  /* en dehors de l'image, on oublie */
            continue;
        for (int j=n.second-1; j<=n.second+1; j++){
            if ((j<0) || (j>=20))   /* en dehors de l'image, on oublie */
                continue;
            if ((i==n.first) && (j==n.second))  /* case actuelle n, on oublie */
                continue;

            if (collisionMap[i][j] == 1)  /* obstacle, terrain non franchissable, on oublie */
                continue;

            if (i != n.first && j != n.second) /* diagonale */
                continue;

            std::pair<int,int> it(i,j);
            if (!deja_present_dans_liste(it, liste_fermee)){
                /* le noeud n'est pas déjà présent dans la liste fermée */

                /* calcul du cout G du noeud en cours d'étude : cout du parent + distance jusqu'au parent */
                tmp.cout_g = liste_fermee[n].cout_g + distance(i,j,n.first,n.second);

                /* calcul du cout H du noeud à la destination */
                tmp.cout_h = distance(i,j,arrivee.x,arrivee.y);
                tmp.cout_f = tmp.cout_g + tmp.cout_h;
                tmp.parent = n;

                if (deja_present_dans_liste(it, liste_ouverte)){
                    /* le noeud est déjà présent dans la liste ouverte, il faut comparer les couts */
                    if (tmp.cout_f < liste_ouverte[it].cout_f){
                        /* si le nouveau chemin est meilleur, on met à jour */
                        liste_ouverte[it]=tmp;
                    }

                    /* le noeud courant a un moins bon chemin, on ne change rien */


                }else{
                    /* le noeud n'est pas présent dans la liste ouverte, on l'y ajoute */
                    liste_ouverte[std::pair<int,int>(i,j)]=tmp;
                }
            }
        }
    }
}

std::pair<int,int> meilleur_noeud(l_noeud& l){
    float m_coutf = l.begin()->second.cout_f;
    std::pair<int,int> m_noeud = l.begin()->first;

    for (l_noeud::iterator i = l.begin(); i!=l.end(); i++)
        if (i->second.cout_f< m_coutf){
            m_coutf = i->second.cout_f;
            m_noeud = i->first;
        }

    return m_noeud;
}

void ajouter_liste_fermee(std::pair<int,int>& p){
    noeud& n = liste_ouverte[p];
    liste_fermee[p]=n;

    /* il faut le supprimer de la liste ouverte, ce n'est plus une solution explorable */
    if (liste_ouverte.erase(p)==0)
        qDebug() << "Erreur, le noeud n'apparaît pas dans la liste ouverte, impossible à supprimer";
    return;
}

std::pair<int, int> FollowingEntity::findNext()
{
    /* l'arrivée est le dernier élément de la liste fermée */
    noeud& tmp = liste_fermee[std::pair<int, int>(arrivee.x,arrivee.y)];

    struct point n;
    std::pair<int,int> prec;
    n.x = arrivee.x;
    n.y = arrivee.y;
    prec.first  = tmp.parent.first;
    prec.second = tmp.parent.second;

    while (prec != std::pair<int,int>(dx,dy)){
        n.x = prec.first;
        n.y = prec.second;

        tmp = liste_fermee[tmp.parent];
        prec.first  = tmp.parent.first;
        prec.second = tmp.parent.second;
    }

    return {n.x, n.y};
}

int FollowingEntity::nextMove()
{
    liste_fermee.clear();
    liste_ouverte.clear();

    int *ac = mc->getPlayerCoords();

    arrivee.x = ac[0]/32;
    arrivee.y = ac[1]/32;

    dx = x()/32;
    dy = y()/32;

    depart.parent.first  = dx;
    depart.parent.second = dy;

    std::pair <int,int> courant;

    /* déroulement de l'algo A* */

    /* initialisation du noeud courant */
    courant.first  = dx;
    courant.second = dy;

    /* ajout de courant dans la liste ouverte */
    liste_ouverte[courant]=depart;
    ajouter_liste_fermee(courant);
    ajouter_cases_adjacentes(courant, mc->getCollisionMap());

    /* tant que la destination n'a pas été atteinte et qu'il reste des noeuds à explorer dans la liste ouverte */
    while( !((courant.first == arrivee.x) && (courant.second == arrivee.y))
           &&
           (!liste_ouverte.empty())
           ){

        /* on cherche le meilleur noeud de la liste ouverte, on sait qu'elle n'est pas vide donc il existe */
        courant = meilleur_noeud(liste_ouverte);

        /* on le passe dans la liste fermée, il ne peut pas déjà y être */
        ajouter_liste_fermee(courant);

        /* on recommence la recherche des noeuds adjacents */
        ajouter_cases_adjacentes(courant, mc->getCollisionMap());
    }

    /* si la destination est atteinte, on remonte le chemin */
    if ((courant.first == arrivee.x) && (courant.second == arrivee.y)){
        std::pair<int, int> coord = findNext();

        if(dx - coord.first == -1 && dy == coord.second){
            return R;
        }
        else if(dx - coord.first == 1 && dy == coord.second){
            return L;
        }
        else if(dx == coord.first && dy - coord.second == -1){
            return D;
        }
        else if(dx == coord.first && dy - coord.second == 1){
            return U;
        }

    }else{
        return -1;
    }
}
