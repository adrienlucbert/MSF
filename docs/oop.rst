.. MSF documentation master file, created by
   sphinx-quickstart on Tue Feb 12 14:40:17 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

============================
Programmation orientée objet
============================

La POO? Quoi c'est?
-------------------

La programmation orientée objet est une méthode de développement très prisée ces
dernières années. On appelle objet une entité définie par des données (simples 
variables appelées propriétés), et des fonctions (appelées méthodes).
La classe est la définition d'un type d'objet. Ainsi, chaque objet est une 
instance de la classe dont il dépend.

Mieux avec un exemple...
------------------------

Dans un RPG, on définit un personnage, entre autres, par son nom et ses points 
de vie.

On aura donc la classe (ou class en anglais) Personnage, qui aura comme 
propriétés :
    - nom
    - pts_vie

.. note::

   Par convention, le nom d'une classe commence par une majuscule.

Ensuite, un personnage peut effectuer différentes actions, parmi lesquelles 
attaquer.

On peut donc compléter notre classe avec ses méthodes :

.. code-block:: none

    class Personnage:
        # properties
        nom
        pts_vie

        # methods
        attaquer(cible)

Notre programme sait maintenant ce qu'est qu'un personnage, on peut lui 
demander d'en créer!

.. tip::

   La plupart des langages orientés objet utilisent le mot-clé **new** pour 
   créer une instance d'une classe (donc un objet).

.. code-block:: none

    dovahkiin = new Personnage(nom = "Dovahkiin", pts_vie = 100)
    alduin = new Personnage(nom = "Alduin", pts_vie = 3000)
    
    dovahkiin->attaquer(alduin)
    alduin->attaquer(dovahkiin)

On a ainsi créé deux instances de la classe Car, deux objets ayant en commun 
leur définition, mais dont les propriétés ont des valeurs différentes.
Chaque instance peut évoluer indépendemment des autres.

Notion d'héritage
-----------------

Une dernière notion à aborder avant de rentrer dans le vif du sujet: l'héritage.
Plusieurs classes peuvent être très proches, avoir seulement quelques 
propriétés ou méthodes différant.
À ce moment là, on utilise l'héritage. On définit une classe qui réunit les 
propriétés et méthodes communes aux autres classes qu'on appelera les enfants, 
puis on définit les enfants, avec seulement les propriétés et méthodes qui leur
sont propres. On précise alors que les classes enfant **héritent** de la classe 
parent, à l'aide d'un mot clé, souvent ``extends``.

Prenons l'exemple de personnages de RPG:

.. code-block:: none

    class Personnage:
        # properties
        nom
        pts_vie

        # methods
        attaquer(cible)

    class Hero extends Personnage:
        # properties
        pts_mana

        # methods
        soigner()

    class Gobelin extends Personnage
        # properties
        nom = "Gobelin" // valeur par défaut pour la propriété nom
        nom_clan

        # methods
        grogner();

Ca donne quoi en C?
-------------------

Le C n'est pas connu pour être un langage orienté objet... Et pour cause, le C 
n'offre aucun support du concept d'objet. Il est en revanche possible de s'en 
approcher en adoptant certaines pratiques.

Vous l'aurez sûrement deviné, on va utiliser des structures pour représenter 
les classes. Les différentes variables seront les propriétés, et il suffira 
de créer des pointeurs sur fonction pour simuler des méthodes.

On aura des constructeurs (constructor en anglais, abrégé ctor), une fonction 
pour chaque classe, destinée à initialiser les propriétés et méthodes d'un  
objet. Parallèlement, on aura des destructeurs (destructor, abrégé dtor) 
pour chaque classe, destiné à "vider" l'objet, soit désallouer l'espace mémoire 
réservé pour ses propriétés.
Le ``ctor`` et le ``dtor`` seront accompagnés d'une fonction ``new``, qui prend 
la place du mot-clé "new" évoqué précédemment, et d'une fonction ``destroy``. 
Le rôle de la fonction new sera d'allouer l'espace mémoire nécessaire pour 
stocker l'objet (malloc la structure), et appeler le ctor correspondant.
Le rôle de la fonction destroy sera d'appeler le dtor correspondant, puis 
de désallouer l'espace mémoire réservé pour l'objet (free la structure).

.. code-block:: c

    /* HEADER */
    typedef struct personnage_s personnage_t;
    void personnage_attaquer(void *);

    struct personnage_s {
        # properties
        char *nom;
        int pts_vie;

        # methods
        void (*attaquer)(void *cible);
    }

    /* /HEADER */

    void *personnage_new(char *nom, int pts_vie)
    {
        personnage_t *st_personnage = malloc(sizeof(personnage_t));

        if (st_personnage == NULL)
            return (NULL);
        personnage_ctor((void *)st_personnage, nom, pts_vie);
        return ((void *)st_personnage);
    }

    void personnage_ctor(void *personnage, char *nom, int pts_vie)
    {
        personnage_t *st_personnage = (personnage_t *)personnage;

        // properties
        st_personnage->nom = strdup(nom);
        st_personnage->pts_vie = pts_vie;

        // methods
        st_personnage->attaquer = personnage_attaquer;
    }

    void personnage_dtor(void *personnage)
    {
        personnage_t *st_personnage = (personnage_t *)personnage;

        free(st_personnage->nom);
        // les autres propriétés et les méthodes n'ont pas été malloc
        // pas besoin de les free
    }

    void personnage_destroy(void *personnage)
    {
        personnage_dtor(personnage);
        free(personnage);
    }

Vous aurez remarqué qu'on passe passe les objets en **void ***. Ce trick nous 
servira à implémenter un système d'héritage. En effet, on pourra par exemple 
utiliser les ctor et dtor de la classe Personnage sur une structure enfant, 
qui a entre autres les propriétés de la classe Personnage, mais qui n'est pas 
de type personnage_t!
Voici donc comment implémenter la classe Gobelin (on ne fera pas Hero, pour 
simplifier et raccourcir ce tutoriel), héritant de la classe Personnage.

.. code-block:: c

    /* HEADER */
    typedef struct gobelin_s gobelin_t;
    void personnage_attaquer(void *);
    void gobelin_grogner(void);

    struct gobelin_s {
        # own properties
        char *nom_clan;

        # own methods
        void (*grogner)(void);

        # properties inherited from personnage_t
        char *nom;
        int pts_vie;

        # methods inherited from personnage_t
        void (*attaquer)(void *cible);
    }

    /* /HEADER */

    void *gobelin_new(char *nom_clan, int pts_vie)
    {
        gobelin_t *st_gobelin = malloc(sizeof(gobelin_t));

        if (st_gobelin == NULL)
            return (NULL);
        gobelin_ctor((void *)st_gobelin, nom_clan, pts_vie);
        return ((void *)st_gobelin);
    }

    void gobelin_ctor(void *gobelin, char *nom_clan, int pts_vie)
    {
        gobelin_t *st_gobelin = (gobelin_t *)gobelin;

        // on appelle le ctor de la classe parent (personnage)
        personnage_ctor((void *)st_gobelin, "Gobelin", pts_vie);

        // own properties
        st_gobelin->nom_clan = strdup(nom_clan);

        // own methods
        st_gobelin->grogner = gobelin_grogner;
    }

    void gobelin_dtor(void *gobelin)
    {
        gobelin_t *st_gobelin = (gobelin_t *)gobelin;

        free(st_gobelin->nom_clan);

        // on appelle le dtor de la classe parent (personnage)
        personnage_dtor((void *)st_gobelin);
    }

    void gobelin_destroy(void *gobelin)
    {
        gobelin_dtor(gobelin);
        free(gobelin);
    }

À partir de là, on peut créer des instances de nos classes à volonté.

.. code-block:: c

    personnage_t *legolas = personnage_new("Legolas", 100);
    gobelin_t *goblin = gobelin_new("Zigarouille", 20);

    legolas->attaquer(goblin);
    goblin->grogner();
    goblin->attaquer(legolas);

    personnage_destroy(legolas);
    gobelin_destroy(goblin);