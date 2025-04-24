from PIL import Image
import csv

class Build_map :

    def Building_map (carte : list) :
        
        carte_Vectorum = Image.new(mode="RGB", size=(len(carte)*8, len(carte[0]*8)))
        for x in range (len(carte)) :
            for y in range (len(carte[x])) :
                lst_tuile = ["CarreBlanc.png", "CarreNoir.png", "DepArr.png", "DepArr.png", "DepArr.png", "DepArr.png"]
                path = "{}\{}".format("Cartes",lst_tuile[int(carte[x][y])])
                carte_Vectorum.paste(Image.open(path, (x*8, y*8)))
        carte_Vectorum.save("carte_Vectorum.png")
    
    Building_map("petite.csv")