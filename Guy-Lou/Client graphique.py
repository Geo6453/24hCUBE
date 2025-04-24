from tkinter import *
from PIL import Image

class interface_graphique :

    def recup_bonus_vect (vecteur : list, map : str) -> tuple :
        fenetre = Tk()
        Name = Label(fenetre, text="jouer a vectorun").grid(row=0, column=1)
    
        photo = PhotoImage(file=map)
        im = Image.open(map)
        width = im.width
        height = im.height
        canvas = Canvas(fenetre,width=width, height=height)
        canvas.create_image(0, 0, anchor=NW, image=photo)
        canvas.grid(row=5, column=1)

        value = StringVar() 
        bouton1 = Radiobutton(fenetre, text="+1.-1", variable=value, value=0).grid(row=1, column=0)
        bouton2 = Radiobutton(fenetre, text="+1.0", variable=value, value=1).grid(row=1, column=1)
        bouton3 = Radiobutton(fenetre, text="+1.+1", variable=value, value=2).grid(row=1, column=2)
        bouton4 = Radiobutton(fenetre, text="0.-1", variable=value, value=3).grid(row=2, column=0)
        bouton5 = Radiobutton(fenetre, text="0.0", variable=value, value=4).grid(row=2, column=1)
        bouton6 = Radiobutton(fenetre, text="0.+1", variable=value, value=5).grid(row=2, column=2)
        bouton7 = Radiobutton(fenetre, text="-1.-1", variable=value, value=6).grid(row=3, column=0)
        bouton8 = Radiobutton(fenetre, text="-1.0", variable=value, value=7).grid(row=3, column=1)
        bouton9 = Radiobutton(fenetre, text="-1.+1", variable=value, value=8).grid(row=3, column=2)
    
        bouton_close = Button(fenetre, text="Jouer", command=fenetre.quit).grid(row=4, column=1)

        bonus_vecteur = ((1, -1),(1, 0),(1, 1),(0, -1),(0, 0),(0, 1),(-1, -1),(-1, 0),(-1, 1))

        fenetre.mainloop()

        bonus =  bonus_vecteur[int(value.get())]
        vecteur[0] += bonus[1]
        vecteur[1] += bonus[0]
        return vecteur

print(interface_graphique.recup_bonus_vect([4, 1], "carte_Vectorun.png"))