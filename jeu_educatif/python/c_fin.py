# Le professeur a visiblement chiffré l'accès en écriture sur les fichiers de résultats pour s'assurer que personne ne
# tricherait. Le message suivant apparaît :
# qzrtxoevztjtdqufnggzfczadnolyknmeaokcxkxzydvmp.qufnvzpbpujpnuchgtnaedrtnkcgkcvinjacxongggdkcXZCG+K+E+Bvzpxczsaggnzxwzltxntzxoztzokdnacxkejxodtlokfm
#
# Voici ce que nous savons sur ce message :
#   - Ce message a été chiffré avec l'algorithme de chiffrement de vigenère
#   - La clé utilisée est de longueur 3
#   - Ce message respecte a peu près les fréquences d'apparition des lettres dans la langue française
#   - Les caractères spéciaux n'ont pas été chiffrés, seules les lettres (minuscule et majuscule) le sont
#
# Pour vous aider vous pourrez vous servir de la variable suivante, qui contiendra le message :
# message = "qzrtxoevztjtdqufnggzfczadnolyknmeaokcxkxzydvmp.qufnvzpbpujpnuchgtnaedrtnkcgkcvinjacxongggdkcXZCG+K+E" \
#          "+Bvzpxczsaggnzxwzltxntzxoztzokdnacxkejxodtlokfm "
#
# Vous aurez également accès à la fonction de déchiffrement de vigenère codée ci-dessous
# Bon courage

def vigenere(word, key):
    key = key.lower()
    message = ""
    i = 0
    for letter in word:
        if letter.isalpha():
            letter_index = 65 if letter.isupper() else 97
            message += chr(((ord(letter) - letter_index)-(ord(key[i%len(key)]) - 97)) % 26 + letter_index)
            i += 1
        else:
            message += letter
    return message

