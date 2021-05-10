import temp


def test():
    if temp.vigenere("a", "a") is None:
        print("Incorrect : aucun retour")
        return False

    test1 = temp.vigenere("avion", "oui")
    if test1 != "mbaat":
        if test1 == "opqch":
            print("Incorrect : ceci est une fonction de chiffrement et non de déchiffrement comme requis")
        elif not test1.isalpha():
            print("Incorrect : mauvais traitement des lettres")
        else:
            print("Incorrect : mauvaise implémentation de l'algorithme")
        return False

    test2 = temp.vigenere("avion", "nope")
    if test2 != "nhtka":
        if test2 == "nhtbz":
            print("Incorrect : la clé ne doit pas avoir de taille définie")
        elif not test2.isalpha():
            print("Incorrect : mauvais traitement des lettres")
        else:
            print("Incorrect : mauvaise implémentation de l'algorithme")
        return False

    test3 = temp.vigenere("avi on", "oui")
    if test3 != "mba at":
        print("Incorrect : espaces non traités")
        return False

    if not isinstance(temp.cle, str):
        print("Incorrect : la clé doit être une chaîne de caractères")
        return False

    if temp.cle != "giovan":
        print("Incorrect : la clé est incorrecte")
        return False

    print(
        "rm gzcbtl qvrnibsme ryb zv lrzbfz q")
    return True


try:
    if not ("vigenere" in dir(temp) and callable(getattr(temp,'vigenere'))):
        print("Incorrect : fonction vigenere(mot, cle) non déclarée")
        answer = False
    else:
        answer = test()
except Exception as e:
    print(type(e).__name__, ":", e)
    answer = False
