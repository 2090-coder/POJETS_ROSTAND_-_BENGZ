# Liste des composants

## Partie Arduino

| Quantité | Composant | Fonction |
|---:|---|---|
| 1 | Arduino Nano | Contrôle principal |
| 1 | HC-SR04 | Détection de la main |
| 1 | Bouton poussoir | Activation et désactivation |
| 1 | Pompe à eau DC | Circulation de l'eau |
| 1 | MOSFET logique ou module relais | Commande de la pompe |
| 1 | Diode de roue libre | Protection de la commande de pompe DC |
| 1 | Alimentation adaptée | Alimentation du système |
| 1 | Tuyau d'eau | Distribution |
| 1 | Réservoir d'eau | Stockage |
| 1 | Récipient de récupération | Collecte de l'eau utilisée |
| Selon le design | LEDs rouges | L1 |
| Selon le design | LEDs orange | L2 |
| Selon le design | LEDs jaunes | L3 |
| Selon le design | LEDs vertes | L4 |
| 1 | LED rouge intérieure | État d'attente |
| 1 | LED verte intérieure | État de lavage |
| Selon le montage | Résistances LED | Limitation du courant |
| Selon le montage | Plaque de prototypage | Assemblage |
| Selon le montage | Fils Dupont | Connexions |

## Partie niveau d'eau de Rostand

| Quantité | Composant | Fonction |
|---:|---|---|
| Selon le schéma | Transistors | Détection et commutation |
| Selon le schéma | Électrodes ou sondes | Détection du niveau |
| Selon le schéma | LEDs | Indication du niveau |
| Selon le schéma | Résistances | Polarisation et limitation |
| Selon le schéma | Alimentation | Alimentation du montage |

## Partie mécanique

- Boîtier vertical de la forme du prototype dessiné
- Support du réservoir
- Support de pompe
- Support du tuyau
- Ouverture de remplissage
- Passage de câbles
- Zone de fixation du HC-SR04
- Zone de fixation des LEDs de progression
- Zone de fixation des LEDs intérieures
- Récipient inférieur de récupération

## Recommandation

Le choix final de la pompe, de l'alimentation, du MOSFET et des résistances doit être confirmé à partir de la tension et du courant nominaux de la pompe réellement disponible.
