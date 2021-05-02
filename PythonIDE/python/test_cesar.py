import temp

def test():
    test1 = temp.cesar("avion", 2)
    if test1 != "ytgml":
        if test1 == "cxkqp":
            print("Incorrect : ceci est une fonction de chiffrement et non de déchiffrement comme requis")
        elif test1 == "_tgml":
            print("Incorrect : mauvais traitement des lettres du début de l'alphabet")
        else:
            print("Incorrect : mauvaise implémentation de l'algorithme")
        return False

    test2 = temp.cesar("avion", -5)
    if test2 != "fants":
        if test2 == "f{nts":
            print("Incorrect : mauvais traitement des lettres de la fin de l'alphabet")
        else:
            print("Incorrect : mauvaise implémentation de l'algorithme")
        return False

    test3 = temp.cesar("avi on", 2)
    if test3 != "ytg ml":
        print("Incorrect : espaces non traités")
        return False

    if not isinstance(temp.cle, int):
        print("Incorrect : la clé doit être un nombre entier")
        return False

    if temp.cle != 7:
        print("Incorrect : la clé est incorrecte")
        return False

    print(
        "sl wyltply jhyhjalyl lza sh slaayl j")
    return True


try:
    if not ("cesar" in dir(temp) and callable(getattr(temp,'cesar'))):
        print("Incorrect : fonction cesar(mot, cle) non déclarée")
        answer = False
    else:
        answer = test()
except Exception as e:
    print(type(e).__name__, ":", e)
    answer = False
