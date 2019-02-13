Listes chaînées
===============

Description
-----------

Les listes chaînées sont utilisées pour stocker dynamiquement les composants du jeu :
    - événements,
    - scènes,
    - objets,
    - etc...

La librairie MSF utilise des listes simplement chaînées et circulaires, 
composées de **nodes**, ou `maillons de la chaîne`.

.. note::

   Le type du d'un node est **node_t**.

Données
-------

    :label: :c:type:`char *` - identifiant du node.
    :next: :c:type:`void *` - élément suivant dans la liste.
    :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *node_new(char *label, void *next);

Crée un nouveau maillon de chaîne.

	**Paramètres**
		:label: :c:type:`char *` - identifiant du node.
		:next: :c:type:`void *` - élément suivant dans la liste. Laisser à NULL pour créer une chaîne d'un seul maillon.

	**Valeur de retour**
		:c:type:`void *` - node

.. c:function:: void node_destroy(void *node);

Détruit un node et son contenu (à l'aide du dtor). Retire le node de la liste à laquelle il appartient.

	**Paramètres**
		:node: :c:type:`void *` - node à détruire.

Utilisation
~~~~~~~~~~~

.. c:function:: void *list_append(void *begin, void *node);

Ajoute un node à la fin d'une liste

	**Paramètres**
		:begin: :c:type:`void *` - node de début de la liste.
		:node: :c:type:`void *` - node à ajouter à la liste.

    **Valeur de retour**
        :c:type:`void *` - node ajouté à la liste

.. c:function:: void *list_destroy(void *begin);

Détruit chaque node d'une liste.

	**Paramètres**
		:begin: :c:type:`void *` - node de début de la liste.

.. c:function:: void list_apply(void *begin, void (*func)(void *));

Applique une fonction à chaque node de la liste.

	**Paramètres**
		:begin: :c:type:`void *` - node de début de la liste.
			:func: :c:type:`void (*)(void *)` - fonction à appliquer aux nodes de la liste.

.. c:function:: void *list_fetch(void *begin, char *label);

Cherche un node dans une liste, en fonction de son label.

	**Paramètres**
		:begin: :c:type:`void *` - node de début de la liste.
        	:label: :c:type:`char *` - label à rechercher dans la liste

    **Valeur de retour**
        :c:type:`void *` - node correspondant à la recherche. NULL si aucun node trouvé.