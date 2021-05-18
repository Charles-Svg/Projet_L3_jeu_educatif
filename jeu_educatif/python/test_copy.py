import temp


def test():
    if temp.deepCopy(temp.files.Dossier()) is None:
        print("Incorrect : aucun retour")
        return False

    fichier1 = temp.files.Fichier(1)
    fichier2 = temp.files.Fichier(2)
    fichier3 = temp.files.Fichier(3)
    fichier4 = temp.files.Fichier(4)
    fichier5 = temp.files.Fichier(5)

    repertoire = temp.files.Dossier([fichier1, fichier2, fichier3, fichier4, fichier5])
    rep2 = temp.deepCopy(repertoire)

    #Vérification que la copie renvoie une liste avec le bon nombre d'éléments
    if rep2.nbElem() != repertoire.nbElem():
        print("Incorrect : erreur de copie")
        return False

    #Vérification que les fichiers soient les mêmes
    for i in range(len(repertoire.fichiers)):
        if rep2.fichiers[i] == repertoire.fichiers[i]:
            print("Incorrect : erreur de copie, fichiers copiés en surface et non en profondeur")
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

if answer:
    import save
    save.valider(1, save.Sauvegarde.COPIE)
