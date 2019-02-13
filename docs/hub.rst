.. MSF documentation master file, created by
   sphinx-quickstart on Tue Feb 12 14:40:17 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

========
Game Hub
========

Introduction
------------

The Game Hub aims to be a container for all data related to the game.

Structure
-----------

.. code-block:: c

    typedef struct msf_hub_s hub_t;

.. code-block:: c

    struct msf_hub_s {
        sfRenderWindow *window;
        void *global_evt;
        unsigned int framerate;
        sfClock *timer;
        void *scene;
    };