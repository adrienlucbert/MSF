Game Scenes
===========

Description
-----------

Les scènes d'un jeu sont les différentes parties du jeu (les différents menus, 
le niveau 1, le niveau 2, etc...). Elles contiennent leurs événements et leurs 
`game objects` propres.

.. note::

   Le type des Game Scene est **scene_t**.

Données
-------

    :objs: :c:type:`void *` - liste des objets de la scène.
    :evts: :c:type:`void *` - liste des événements de la scène.
    :cam_speed: :c:type:`sfVector2f` - vitesse de déplacement de la caméra de la scène.
    :cam_pos: :c:type:`sfVector2f` - position de la caméra de la scène.

    .. admonition:: Propriétés héritées de node_t

        :label: :c:type:`char *` - identifiant du node.
        :next: :c:type:`void *` - élément suivant dans la liste.
        :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *scene_new(void);

Crée une nouvelle scene.

	**Valeur de retour**
		:c:type:`void *` - scene

.. c:function:: void scene_destroy(void *scene);

Détruit une scène et son contenu.

	**Paramètres**
		:scene: :c:type:`void *` - scène à détruire.

Remplissage
~~~~~~~~~~~

.. c:function:: void scene_add_evt(void *scene, void *evt, char *label);

Ajoute un événement à la fin de la liste evts d'une scène.

	**Paramètres**
		:scene: :c:type:`void *` - scène à laquelle ajouter l'événement.

		:evt: :c:type:`void *` - événement à ajouter à la scène.

		:label: :c:type:`char *` - Identifiant de l'événement. Laisser à NULL pour ne pas définir d'identifiant.

.. c:function:: void scene_add_obj(void *scene, void *obj, char *label);

Ajoute un objet à la fin de la liste objs d'une scène.

	**Paramètres**
		:scene: :c:type:`void *` - scène à laquelle ajouter l'objet.

		:obj: :c:type:`void *` - objet à ajouter à la scène.

		:label: :c:type:`char *` - Identifiant de l'objet. Laisser à NULL pour ne pas définir d'identifiant.