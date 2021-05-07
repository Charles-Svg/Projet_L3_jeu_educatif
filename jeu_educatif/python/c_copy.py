# Afin de copier les dossiers du prof pour les ajouter sur votre clé USB, vous devrez développer une fonction
# deepCopy prenant en paramètre un Dossier et retournant une copie en profondeur de ce dossier. Pour se faire,
# vous devrez importer le module files. Ce module comporte une définition de la classe Fichier, définie comme ayant
# un attribut taille étant un entier et une méthode copy() (que vous pourrez utiliser) ainsi que la classe Dossier
# définie comme ayant un attribut fichiers étant une liste des fichiers qu'il contient ainsi que les méthodes
# addFichiers(listeDeFichiers) qui ajoute au dossier les fichiers dans la liste, supprFichier() qui supprime le dernier
# fichier ajouté ainsi que la méthode nbElem() retournant le nombre de fichiers dans le dossier.
#
# Aide :
#   - Afin d'effectuer une copie en profondeur d'un objet, il vous faut recréer une instance de la classe de cet objet
# et, pour chaque attribut, il vous faudra l'instancier avec une copie en profondeur de l'attribut.
#   - Afin d'ajouter un élément à une liste, vous pouvez utiliser la méthode append(element)
#   - Afin de vous aider, une arborescence de test vous est mis a dispositions :
#       5 fichiers nommés fichier1, fichier2, fichier3, fichier4 et fichier5
#       1 dossier nommé répertoire contenant les 5 fichiers
import files


def deepCopy(dossier):
    # A compléter
    return


