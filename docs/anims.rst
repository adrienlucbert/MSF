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