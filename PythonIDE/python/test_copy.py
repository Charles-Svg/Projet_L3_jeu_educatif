import temp


def test():
    if temp.deepCopy(temp.notes.Dossier()) is None:
        print("Incorrect : aucun retour")
        return False

    fichier1 = temp.notes.Fichier()
    fichier2 = temp.notes.Fichier()
    fichier3 = temp.notes.Fichier()
    fichier4 = temp.notes.Fichier()
    fichier5 = temp.notes.Fichier()

    repertoire = temp.notes.Dossier([fichier1, fichier2, fichier3, fichier4, fichier5])
    rep2 = temp.deepCopy(repertoire)

    #Vérification que la copie renvoie une liste avec le bon nombre d'éléments
    if rep2.nbElem() != repertoire.nbElem():
        print("Incorrect : erreur de copie")
        return False

    repertoire.supprFichier()

    #Vérification que la suppression d'un élémet dans repertoire n'influe pas sur rep2
    if rep2.nbElem() == repertoire.nbElem():
        print("Incorrect : copie en surface et non en profondeur")
        return False

    print("Copie effectuée avec succès, vous pouvez fermer cette fenêtre")
    return True


try:
    if not ("deepCopy" in dir(temp) and callable(getattr(temp,'deepCopy'))):
        print("Incorrect : fonction deepCopy(dossier) non déclarée")
        answer = False
    else:
        answer = test()
except Exception as e:
    print(type(e).__name__, ":", e)
    answer = False