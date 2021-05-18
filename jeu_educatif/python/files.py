class Fichier:
    def __init__(self, sizeMb=30):
        self.sizeMb = sizeMb

    def copy(self):
        return Fichier(self.sizeMb)


class Dossier:
    def __init__(self, fichiers=[]):
        self.fichiers = fichiers

    def addFichiers(self, liste):
        for elem in liste:
            self.fichiers.append(elem)

    def supprFichier(self):
        self.fichiers.remove(self.fichiers[len(self.fichiers) - 1])

    def nbElem(self):
        return len(self.fichiers)


fichier1 = Fichier(5)
fichier2 = Fichier(6)
fichier3 = Fichier(1)
fichier4 = Fichier(8)
fichier5 = Fichier(7)

repertoire = Dossier([fichier1, fichier2, fichier3, fichier4, fichier5])
