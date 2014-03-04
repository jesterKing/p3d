p3d.in c++ viewer
=================

This is using git submodules for external libs (glm), so:

    $git submodule init
    $git submodule update

Contains following projects:

 - libViewer: the viewer library
 - p3d-qt: Qt app using libViewer
 - p3d-android: Android NDK app using libViewer
 - p3d-em: Emscripten test using libViewer