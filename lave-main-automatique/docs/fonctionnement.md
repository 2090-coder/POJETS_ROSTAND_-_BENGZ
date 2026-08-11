# Fonctionnement

## État initial

Lorsque le système est désactivé, toutes les LEDs de progression et la pompe sont arrêtées.

Lorsque le système est activé sans main détectée, l'éclairage intérieur rouge est actif.

## Détection de la main

Le HC-SR04 mesure régulièrement la distance.

Si aucune mesure valide n'est obtenue ou si la main est à plus de 40 cm, les LEDs de progression restent éteintes et la pompe reste arrêtée.

## Progression

À une distance comprise entre 30 et 40 cm, L1 rouge est allumée.

À une distance comprise entre 20 et 30 cm, L1 rouge et L2 orange sont allumées.

À une distance comprise entre 10 et 20 cm, L1 rouge, L2 orange et L3 jaune sont allumées.

À une distance inférieure ou égale à 10 cm, L1, L2, L3 et L4 vert sont allumées et la pompe est activée.

## Retrait de la main

Lorsque la main quitte la zone de détection, la pompe s'arrête.

Les LEDs de progression s'éteignent.

L'éclairage intérieur rouge revient à l'état d'attente.

## Bouton

Un appui sur le bouton inverse l'état du système.

Un appui active le système.

Un nouvel appui désactive le système.

Le programme utilise une temporisation logicielle pour limiter les effets des rebonds mécaniques du bouton.

## Niveau d'eau

Le niveau d'eau est traité indépendamment par le montage à transistors de Mirimo MUHINDO Rostand.

Le fonctionnement du niveau d'eau ne dépend pas de la boucle principale Arduino.
