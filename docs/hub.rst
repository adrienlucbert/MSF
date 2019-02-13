Game Hub
========

Description
-----------

Le Game Hub est un conteneur pour toutes les données du jeu.

.. note::

   Le type du Game Hub est **hub_t**.

Données
-------

    :window: :c:type:`sfRenderWindow *` - la fenêtre de rendu du jeu.
    :global_evts: :c:type:`void *` - événements à portée globale (ne dépendant pas d'une scène).
    :framerate: :c:type:`unsigned int` - taux de rafraîchissement du jeu.
    :timer: :c:type:`sfClock *` - clock servant à gérer le rafraîchissement du jeu.
    :scenes: :c:type:`void *` - liste des scènes du jeu.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *hub_new(char *title, sfVector2i size, sfUint32 style);

Crée un nouveau hub.

	**Paramètres**
		:title: :c:type:`char *` - titre de la fenêtre de jeu.

		:size: :c:type:`sfVector2i` - dimensions de la fenêtre.

		:style: :c:type:`sfUint32` - Vous devez utiliser au moins une des options ci-dessous :

			* ``sfNone`` : Aucune option de style ne sera utilisée.
			* ``sfResize`` : Ajoute un bouton **resize** permettant de redimensionner la fenêtre.
			* ``sfClose`` : Ajoute un bouton **close** permettant de fermer la fenêtre.
			* ``sfFullscreen`` : Affiche la fenêtre en plein écran.
                Pour combiner plusieurs options, séparez-les avec un pipe ``|``

	**Valeur de retour**
		:c:type:`void *` - hub

.. c:function:: void hub_destroy(void *hub);

Détruit un hub et son contenu.

	**Paramètres**
		:hub: :c:type:`void *` - hub à détruire.

Remplissage
~~~~~~~~~~~

.. c:function:: void hub_add_global_evt(void *hub, void *global_evt, char *label);

Ajoute un événement à la fin de la liste global_evts du hub.

	**Paramètres**
		:hub: :c:type:`void *` - hub auquel ajouter l'événement.

		:global_evt: :c:type:`void *` - événement à ajouter au hub.

		:label: :c:type:`char *` - Identifiant de l'événement. Laisser à NULL pour ne pas définir d'identifiant.

.. c:function:: void hub_add_scene(void *hub, void *scene, char *label);

Ajoute une scène à la fin de la liste scenes du hub.

	**Paramètres**
		:hub: :c:type:`void *` - hub auquel ajouter la scène.

		:scene: :c:type:`void *` - scène à ajouter au hub.

		:label: :c:type:`char *` - Identifiant de la scène. Laisser à NULL pour ne pas définir d'identifiant.

Utilisation
~~~~~~~~~~~

.. c:function:: void window_render(hub_t *hub);

Actualise le rendu du jeu.

	**Paramètres**
		:hub: :c:type:`void *` - hub contenant la window à actualiser.