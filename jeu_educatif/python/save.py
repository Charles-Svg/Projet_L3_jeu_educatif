from enum import Enum
import json


class Sauvegarde(Enum):
    COPIE = "Copie"
    CESAR = "Cesar"
    VIGENERE = "Vigenere"
    SUBSTITUTION = "Substitution"
    FIN = "Fin"


def valider(chapitre, epreuve):
    with open("save.json", "r") as f:
        save = json.load(f)
        save["Chapitre " + str(chapitre)][epreuve.value] = True
        json.dump(save, open("save.json", "w"))
        return
