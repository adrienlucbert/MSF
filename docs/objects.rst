Game Objects
============

Description
-----------

Les Game Objects sont tous les composants visuels du jeu: textes, boutons 
(inputs), blocs, personnages, ...

.. note::

   Le type du Game Object est **obj_t**.

La structure obj_t représente la classe mère, mais on distinguera plus 
particulièrement trois classes enfants :
    - :c:type:`text_obj_t` - objet texte.
    - :c:type:`anim_obj_t` - objet "`animé`", possédant une ou plusieurs animations et textures.
    - :c:type:`input_obj_t` - objet "`input`", bouton, champ de saisie, ...

obj_t: classe mère
==================

Données
-------

    :scope: :c:type:`evt_scope` - domaine d'activation de l'événement :
    :fixing: :c:type:`obj_fixing` - effet de la caméra de la scène sur l'objet :

        * ``fixed`` : l'objet se déplace avec la caméra de la scène.
        * ``absolute`` : l'objet n'est pas affecté par la caméra de la scène.
    :type: :c:type:`obj_type` - type de l'objet :

        - ``text`` : text_obj_t
        - ``animated`` : anim_obj_t
        - ``input`` : input_obj_t
    :group: :c:type:`int` - group de l'objet (identifiant de groupe).
    :state: :c:type:`sfBool` - état de l'objet (actif ou inactif). Si l'objet est inactif, il ne sera pas rendu.
    :speed: :c:type:`sfVector2f` - vecteur de déplacement de l'objet.
    :pos: :c:type:`sfVector2f` - position de l'objet dans la scène.
    :rotation: :c:type:`float` - rotation de l'objet.
    :render: :c:type:`void (*)(hub_t *, void *)` - fonction de rendu de l'objet.
    :mouse_evt: :c:type:`obj_mouse_evt_t` - état de l'objet par rapport aux événement de la souris:

        * :focus: :c:type:`sfBool` - sfTrue si l'objet est le dernier élément cliqué.
        * :hover: :c:type:`sfBool` - sfTrue si la souris survole l'objet.
        * :active: :c:type:`sfBool` - sfTrue si le clic gauche de la souris est maintenu sur l'objet.
        * :x: :c:type:`int` - dernière position de la souris sur l'objet (en x).
        * :y: :c:type:`int` - dernière position de la souris sur l'objet (en y).

    .. admonition:: Propriétés héritées de node_t

        :label: :c:type:`char *` - identifiant du node.
        :next: :c:type:`void *` - élément suivant dans la liste.
        :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *obj_new(obj_type type);

Crée un nouveau obj_t.

	**Paramètres**
		:type: :c:type:`obj_type` - type de l'objet à créer :

            * ``text`` : text_obj_t
            * ``animated`` : anim_obj_t
            * ``input`` : input_obj_t

	**Valeur de retour**
		:c:type:`void *` - objet

.. c:function:: void obj_destroy(void *obj);

Détruit un objet et son contenu

	**Paramètres**
		:obj: :c:type:`void *` - objet à détruire.

text_obj_t: objet texte
=======================

Données
-------

    :text: :c:type:`sfText` - élément CSFML de texte.
    :font: :c:type:`sfFont` - police CSFML.
    :color: :c:type:`sfColor` - couleur CSFML.
    :char_size: :c:type:`unsigned int` - taille des caractères.
    :str: :c:type:`char *` - chaîne de caractères à afficher.

    .. admonition:: Propriétés héritées de obj_t

        :fixing: :c:type:`obj_fixing` - effet de la caméra de la scène sur l'objet :

            * ``fixed`` : l'objet se déplace avec la caméra de la scène.
            * ``absolute`` : l'objet n'est pas affecté par la caméra de la scène.
        :type: :c:type:`obj_type` - type de l'objet :

            * ``text`` : text_obj_t
            * ``animated`` : anim_obj_t
            * ``input`` : input_obj_t
        :group: :c:type:`int` - group de l'objet (identifiant de groupe).
        :state: :c:type:`sfBool` - état de l'objet (actif ou inactif). Si l'objet est inactif, il ne sera pas rendu.
        :speed: :c:type:`sfVector2f` - vecteur de déplacement de l'objet.
        :pos: :c:type:`sfVector2f` - position de l'objet dans la scène.
        :rotation: :c:type:`float` - rotation de l'objet.
        :render: :c:type:`void (*)(hub_t *, void *)` - fonction de rendu de l'objet.
        :mouse_evt: :c:type:`obj_mouse_evt_t` - état de l'objet par rapport aux événement de la souris:

            * :focus: :c:type:`sfBool` - sfTrue si l'objet est le dernier élément cliqué.
            * :hover: :c:type:`sfBool` - sfTrue si la souris survole l'objet.
            * :active: :c:type:`sfBool` - sfTrue si le clic gauche de la souris est maintenu sur l'objet.
            * :x: :c:type:`int` - dernière position de la souris sur l'objet (en x).
            * :y: :c:type:`int` - dernière position de la souris sur l'objet (en y).

    .. admonition:: Propriétés héritées de node_t

        :label: :c:type:`char *` - identifiant du node.
        :next: :c:type:`void *` - élément suivant dans la liste.
        :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *text_obj_new(char *str);

Crée un nouveau text_obj_t.

	**Paramètres**
		:type: :c:type:`char *str` - chaîne de caractères de l'objet texte.

	**Valeur de retour**
		:c:type:`void *` - objet texte

.. c:function:: void text_obj_destroy(void *text_obj);

Détruit un objet texte et son contenu

	**Paramètres**
		:obj: :c:type:`void *` - objet texte à détruire.

anim_obj_t: objet animé
=======================

Données
-------

    :anims: :c:type:`void *` - liste des animations de l'objet.

    .. admonition:: Propriétés héritées de obj_t

        :fixing: :c:type:`obj_fixing` - effet de la caméra de la scène sur l'objet :

            * ``fixed`` : l'objet se déplace avec la caméra de la scène.
            * ``absolute`` : l'objet n'est pas affecté par la caméra de la scène.
        :type: :c:type:`obj_type` - type de l'objet :

            * ``text`` : text_obj_t
            * ``animated`` : anim_obj_t
            * ``input`` : input_obj_t
        :group: :c:type:`int` - group de l'objet (identifiant de groupe).
        :state: :c:type:`sfBool` - état de l'objet (actif ou inactif). Si l'objet est inactif, il ne sera pas rendu.
        :speed: :c:type:`sfVector2f` - vecteur de déplacement de l'objet.
        :pos: :c:type:`sfVector2f` - position de l'objet dans la scène.
        :rotation: :c:type:`float` - rotation de l'objet.
        :render: :c:type:`void (*)(hub_t *, void *)` - fonction de rendu de l'objet.
        :mouse_evt: :c:type:`obj_mouse_evt_t` - état de l'objet par rapport aux événement de la souris:

            * :focus: :c:type:`sfBool` - sfTrue si l'objet est le dernier élément cliqué.
            * :hover: :c:type:`sfBool` - sfTrue si la souris survole l'objet.
            * :active: :c:type:`sfBool` - sfTrue si le clic gauche de la souris est maintenu sur l'objet.
            * :x: :c:type:`int` - dernière position de la souris sur l'objet (en x).
            * :y: :c:type:`int` - dernière position de la souris sur l'objet (en y).

    .. admonition:: Propriétés héritées de node_t

        :label: :c:type:`char *` - identifiant du node.
        :next: :c:type:`void *` - élément suivant dans la liste.
        :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *anim_obj_new(void);

Crée un nouveau anim_obj_t.

	**Valeur de retour**
		:c:type:`void *` - objet animé

.. c:function:: void anim_obj_destroy(void *anim_obj);

Détruit un objet texte et son contenu

	**Paramètres**
		:anim_obj: :c:type:`void *` - objet animé à détruire.

input_obj_t: objet input
========================

Données
-------

    :value: :c:type:`void *` - valeur de l'input (texte, nombre, ...).

    .. admonition:: Propriétés héritées de obj_t

        :fixing: :c:type:`obj_fixing` - effet de la caméra de la scène sur l'objet :

            * ``fixed`` : l'objet se déplace avec la caméra de la scène.
            * ``absolute`` : l'objet n'est pas affecté par la caméra de la scène.
        :type: :c:type:`obj_type` - type de l'objet :

            * ``text`` : text_obj_t
            * ``animated`` : anim_obj_t
            * ``input`` : input_obj_t
        :group: :c:type:`int` - group de l'objet (identifiant de groupe).
        :state: :c:type:`sfBool` - état de l'objet (actif ou inactif). Si l'objet est inactif, il ne sera pas rendu.
        :speed: :c:type:`sfVector2f` - vecteur de déplacement de l'objet.
        :pos: :c:type:`sfVector2f` - position de l'objet dans la scène.
        :rotation: :c:type:`float` - rotation de l'objet.
        :render: :c:type:`void (*)(hub_t *, void *)` - fonction de rendu de l'objet.
        :mouse_evt: :c:type:`obj_mouse_evt_t` - état de l'objet par rapport aux événement de la souris:

            * :focus: :c:type:`sfBool` - sfTrue si l'objet est le dernier élément cliqué.
            * :hover: :c:type:`sfBool` - sfTrue si la souris survole l'objet.
            * :active: :c:type:`sfBool` - sfTrue si le clic gauche de la souris est maintenu sur l'objet.
            * :x: :c:type:`int` - dernière position de la souris sur l'objet (en x).
            * :y: :c:type:`int` - dernière position de la souris sur l'objet (en y).

    .. admonition:: Propriétés héritées de node_t

        :label: :c:type:`char *` - identifiant du node.
        :next: :c:type:`void *` - élément suivant dans la liste.
        :dtor: :c:type:`void (*)(void *)` - fonction `destructor` du node.

Fonctions
---------

Initialisation
~~~~~~~~~~~~~~

.. c:function:: void *input_obj_new(void);

Crée un nouveau input_obj_t.

	**Valeur de retour**
		:c:type:`void *` - objet input

.. c:function:: void input_obj_destroy(void *input_obj);

Détruit un objet input et son contenu

	**Paramètres**
		:input_obj: :c:type:`void *` - objet input à détruire.
