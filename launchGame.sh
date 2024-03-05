#!/bin/bash
# Définir le chemin d'accès à la bibliothèque pour inclure le dossier courant
export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
# Lancer le jeu (remplacez 'YourGameExecutable' par le nom réel de votre exécutable)
./Game
