Game Event
==========

Description
-----------

Les Game Events sont des fonctions qui sont exécutées sous certaines conditions tout au long du jeu.

.. note::

   Le type du Game Event est **evt_t**.

Données
-------

    :scope: :c:type:`evt_scope` - domaine d'activation de l'événement :

        * ``context`` : condition de l'événement vérifiée à chaque actualisation du rendu du jeu.
	* ``inputs`` : condition de l'événement vérifiée à chaque fois que le jeu reçoit un input (clavier, souris, etc...).
    :evt: :c:type:`void (*)(hub_t *, sfEvent)` - fonction appelée par l'événement.

    .. admonition:: Propriétés héritées de node_t

        :label: :c:type:`char *` - identifiant du node.
        :next: :c:type:`void *` - élément suivant dans la liste.
        :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *evt_new(void (*fn)(hub_t *, sfEvent), evt_scope scope);

Crée un nouvel événement.

	**Paramètres**
		:fn: :c:type:`void (*)(hub_t *, sfEvent)` - fonction appelée par l'événement.

		:scope: :c:type:`evt_scope` - domaine d'activation de l'événement :

                * ``context`` : condition de l'événement vérifiée à chaque actualisation du rendu du jeu.
                * ``inputs`` : condition de l'événement vérifiée à chaque fois que le jeu reçoit un input (clavier, souris, etc...).

	**Valeur de retour**
		:c:type:`void *` - événement

.. c:function:: void evt_destroy(void *evt);

Détruit un événement.

	**Paramètres**
		:evt: :c:type:`void *` - événement à détruire.