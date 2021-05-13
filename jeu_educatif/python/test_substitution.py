import temp


def test():
    if temp.substitution("a", "a") is None:
        print("Incorrect : aucun retour")
        return False

    test1 = temp.substitution("avion", "xylophone")
    if test1 != "ixodg":
        if test1 == "xtaig":
            print("Incorrect : ceci est une fonction de chiffrement et non de déchiffrement comme requis")
        elif not test1.isalpha():
            print("Incorrect : mauvais traitement des lettres")
        else:
            print("Incorrect : mauvaise implémentation de l'algorithme")
        return False

    test2 = temp.substitution("avion", "qsdfghjklmwxcvbnazertyuiop")
    if test2 != "qnxyp":
        if not test2.isalpha():
            print("Incorrect : mauvais traitement des lettres")
        else:
            print("Incorrect : mauvaise implémentation de l'algorithme")
        return False

    test3 = temp.substitution("avi on", "xylophone")
    if test3 != "ixo dg":
        print("Incorrect : espaces non traités")
        return False

    if not isinstance(temp.cle, str):
        print("Incorrect : la clé doit être une chaîne de caractères")
        return False

    if temp.cle != "azertyuiop":
        print("Incorrect : la clé est incorrecte")
        return False

    print(
        "ct mkgolotdt eakaemtkt tlm ca ctmmkt o")
    return True


try:
    if not ("substitution" in dir(temp) and callable(getattr(temp,'substitution'))):
        print("Incorrect : fonction substitution(mot, cle) non déclarée")
        answer = False
    else:
        answer = test()
except Exception as e:
    print(type(e).__name__, ":", e)
    answer = False

if answer:
    import save
    save.valider(2, save.Sauvegarde.SUBSTITUTION)
