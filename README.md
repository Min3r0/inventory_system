
# 🎮 Inventory System

## Description du Projet

Ce projet a été conçu durant ma deuxième année d'études dans le but de créer un système de gestion d'inventaire intégré à une boutique. Il permet au joueur principal d'acheter des objets disponibles dans un magasin et de gérer son inventaire en fonction de ses ressources et de son niveau. Le programme met en avant les pratiques liées à la programmation orientée objet en C++ et simule des interactions typiques d'un jeu d'aventure/RPG.

## 🛒 Fonctionnalités

- **Gestion du Magasin** : Visualisation des objets disponibles avec leurs caractéristiques détaillées (force, défense, soins, niveau requis, prix).
- **Achat d'Objets** : Le joueur peut acheter des objets s'il dispose de suffisamment d'argent et si le niveau requis est respecté.
- **Système d'Inventaire** : Ajout des objets achetés dans l'inventaire du joueur.
- **Compatibilité avec le Niveau** : Vérification automatique si les objets dans l'inventaire peuvent ou non être équipés selon le niveau du personnage.
- **Système Financier Simplifié** : Gestion des paiements et suivi de l'argent restant.

## 💡 Structure de Code

Le projet repose sur une conception orientée objet, avec des classes définies comme suit :

- **Classe `Personnage`** : Gère les interactions du joueur principal, son argent, ses caractéristiques (force, défense, soin, niveau) et les objets dans son inventaire.
- **Classe Abstraite `Item`** : Fournit une base pour les différents types d'objets.
- **Classes Dérivées** :
  - `Arme` : Définit les objets de type arme, augmentant les forces d'attaque.
  - `Armure` : Définit les objets de type armure, augmentant les capacités de défense.
  - `Talisman` : Définit les objets de type talisman, apportant des capacités de soin.

## 🎮 Exemple d'Exécution

Lors de l'exécution, le programme affiche :

1. La liste des articles disponibles dans le magasin.
2. Les articles achetés par le joueur, en tenant compte de l'argent disponible.
3. Les objets ajoutés à l'inventaire avec validation du niveau pour permettre ou non leur utilisation.

## 🛠️ Technologies Utilisées

- **Langage** : C++
- **Paradigme** : Programmation orientée objet

## 🧾 Instructions pour Compiler et Exécuter

1. Clonez ce projet :
   ```bash
   git clone https://github.com/Min3r0/inventory_system.git
   ```
2. Assurez-vous d'avoir un compilateur C++ (ex : GCC).
3. Compilez le fichier `main.cpp` :
   ```bash
   g++ -o inventory_system main.cpp
   ```
4. Lancez le programme compilé :
   ```bash
   ./inventory_system
   ```

## 💡 Points forts du projet

1. **Ajout d'objets au magasin** : Modifiez la fonction `main()` pour personnaliser les articles disponibles en magasin.
2. **Personnalisation des achats** : Modifiez l'index des articles dans le tableau `IndexItemBuy` pour simuler les choix du joueur.

## Points forts du projet

- Respect des concepts fondamentaux de la POO.
- Simulation réaliste d'un mécanisme de boutique et d'inventaire, adaptable à un jeu complet.
- Conception claire et modulaire.

---
Créé par Romain AUGÉ