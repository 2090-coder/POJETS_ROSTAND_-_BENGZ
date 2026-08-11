# Conception du boîtier

## Forme

Le boîtier reprend la forme générale du croquis de l'équipe : une structure verticale, arrondie sur les côtés, avec une ouverture supérieure pour le remplissage du réservoir et une zone centrale dédiée au lavage des mains.

## Vue fonctionnelle

```text
             OUVERTURE
                 |
        +-------------------+
       /      RESERVOIR      \
      /                       \
     |   L1             L1    |
     |   L2             L2    |
     |   L3             L3    |
     |   L4             L4    |
     |                       |
     |        HC-SR04        |
     |           |           |
     |        ZONE MAIN      |
     |           |           |
     |       SORTIE EAU      |
     |                       |
     |        TECHNOVA       |
      \                     /
       +-------------------+
                 |
          RECIPIENT EAU
```

## Répartition

### Partie supérieure

Réservoir d'eau propre.

Ouverture de remplissage.

Circuit de niveau d'eau à transistors.

### Partie centrale

HC-SR04 orienté vers la zone où l'utilisateur place les mains.

Tuyau de distribution placé sous ou à proximité de la zone de détection.

Éclairage intérieur rouge et vert visible par l'utilisateur.

### Partie latérale

Deux guides lumineux peuvent être disposés en forme convergente vers la zone centrale.

La séquence lumineuse est rouge, orange, jaune, vert.

### Partie inférieure

Pompe et raccordement hydraulique protégés contre les projections d'eau.

Récipient amovible pour récupérer l'eau utilisée.

## Fabrication

Les dimensions définitives doivent être déterminées à partir des dimensions réelles du réservoir, de la pompe, du tuyau, du récipient et de l'électronique disponibles.

Le compartiment électronique doit être séparé de la zone contenant l'eau.

Le boîtier doit permettre le démontage pour les essais et la maintenance.
