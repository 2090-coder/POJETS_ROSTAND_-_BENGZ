# Lave-mains automatique

## Projet

Prototype de lave-mains automatique développé par l'équipe TECHNOVA dans le dépôt POJETS_ROSTAND_-_BENGZ.

## Équipe

- Salomon BENGZ
- Mirimo MUHINDO Rostand

## Objectif

Concevoir un lave-mains autonome capable de détecter la position des mains, de guider l'utilisateur par une progression lumineuse et de commander automatiquement une pompe à eau.

## Architecture

Le système est séparé en deux parties.

### Partie Arduino

- Arduino Nano
- HC-SR04 pour la détection des mains
- Bouton poussoir pour l'activation et la désactivation
- Quatre niveaux lumineux extérieurs
- Éclairage intérieur rouge et vert
- Commande de pompe par transistor MOSFET ou module relais
- Pompe à eau
- Tuyau de distribution

### Partie niveau d'eau

La détection du niveau d'eau est réalisée par Mirimo MUHINDO Rostand avec un montage électronique à transistors.

Cette partie fonctionne indépendamment du programme Arduino et ne nécessite pas de code.

## Progression lumineuse

| Ligne | Couleur | État |
|---|---|---|
| L1 | Rouge | Main trop éloignée |
| L2 | Orange | Main en approche |
| L3 | Jaune | Main proche |
| L4 | Vert | Position correcte |

Les lignes s'allument progressivement lorsque la main se rapproche de la zone de lavage.

Lorsque L4 est atteinte, l'Arduino active la pompe.

## Éclairage intérieur

- Rouge lorsque le système attend une main.
- Vert lorsque la main atteint la zone de lavage et que la pompe est active.

## Structure

```text
lave-main-automatique/
├── README.md
├── arduino/
│   └── lave_main_automatique.ino
├── docs/
│   ├── cablage.md
│   ├── cahier-des-charges.md
│   └── fonctionnement.md
└── hardware/
    ├── boitier.md
    └── liste-composants.md
```

## Principe général

```text
Bouton -> Arduino Nano -> HC-SR04 -> traitement de distance
                                      |
                                      +-> L1 Rouge
                                      +-> L2 Orange
                                      +-> L3 Jaune
                                      +-> L4 Vert
                                      +-> Pompe
                                      +-> Éclairage intérieur

Circuit de niveau d'eau à transistors -> indicateurs de niveau
```

## Sécurité électrique

La pompe ne doit pas être alimentée directement par une sortie de l'Arduino Nano. Une interface de puissance est obligatoire. L'alimentation de la pompe doit être adaptée à sa tension et à son courant nominaux.
