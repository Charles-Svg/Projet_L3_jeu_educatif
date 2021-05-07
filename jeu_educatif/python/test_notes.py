import temp


def test():
    notes2 = {"Killian" : 18,
             "Josh" : 12.5,
             "Ted" : 9.9,
             "Charles" : 20,
             "Dylan" : 6.1,
             "Kevin" : 11.2,
             "Jason" : 3,
              temp.notes.getpass.getuser() : 20}

    if notes2 != temp.notes.notes:
        if temp.notes.notes[temp.notes.getpass.getuser()] == 0.5:
            print("Incorrect : vous n'avez pas modifié votre note")
        elif temp.notes.notes[temp.notes.getpass.getuser()] < 20:
            print("Incorrect : ne vous sous-estimez pas, mettez vous la meilleure note !")
        elif temp.notes.notes[temp.notes.getpass.getuser()] > 20:
            print("Incorrect : plus de 20 ? Sérieusement ?")
        else:
            print("Incorrect : ne modifiez que votre note")
        return False
    print("Vous avez correctement modifié votre note. Vous pouvez fermer cette fenètre")
    return True


try:
    if not ("notes" in dir(temp)):
        print("Incorrect : le module notes n'a pas été importé")
        answer = False
    else:
        answer = test()
except Exception as e:
    print(type(e).__name__, ":", e)
    answer = False
