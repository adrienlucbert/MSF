Game Object Animation
=====================

Description
-----------

Une animation rassemble une ou plusieurs textures (frames) pour les afficher tour à tour.

.. note::

   Le type d'une animation est **anim_t**.

Données
-------

    :sprite: :c:type:`sfSprite *` - élément CSFML de sprite.
    :scale: :c:type:`sfVector2f` - échelle de rendu de l'animation (taille proportionnelle).
    :origin: :c:type:`sfVector2f` - origine des transformations.
    :rotation: :c:type:`float` - rotation de l'image.
    :frame_duration: :c:type:`unsigned int` - durée d'une frame dans l'animation.
    :timer: :c:type:`sfClock *` - clock servant à gérer le défilement des frames.
    :frames: :c:type:`void *` - listes des textures (frames).

    .. admonition:: Propriétés héritées de node_t

        :label: :c:type:`char *` - identifiant du node.
        :next: :c:type:`void *` - élément suivant dans la liste.
        :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *anim_new(char *filepath, int nb_frames, uint frame_duration);

Crée une nouvelle animation.

	**Paramètres**
		:filepath: :c:type:`char *` - chemin de la spritesheet de l'animation.
		:nb_frames: :c:type:`int` - nombre de frames contenues dans la spritesheet (en horizontal).
        :frame_duration: :c:type:`unsigned int` - durée d'une frame dans l'animation (en ms).

	**Valeur de retour**
		:c:type:`void *` - animation

.. c:function:: void anim_destroy(void *anim);

Détruit un objet et son contenu

	**Paramètres**
		:anim: :c:type:`void *` - animation à détruire.

Setters
~~~~~~~

.. c:function:: void anim_set_frames(void *anim, char *filepath, int nb_frames);

Initialise la liste de frames d'une animation à partir d'une spritesheet.

	**Paramètres**
		:anim: :c:type:`void *` - animation affectée.
		:filepath: :c:type:`char *` - chemin de la spritesheet de l'animation.
        :nb_frames: :c:type:`int` - nombre de frames contenues dans la spritesheet (en horizontal).