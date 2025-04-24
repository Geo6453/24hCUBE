import tkinter
import os
import json
from convertion json.py import Convert_json

class CommandSenderApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Command Sender")

        self.statut = int(input("Entrez votre statut : joueur 0 / spectateur 1"))

        # self.entry = tk.Entry(root, width=50)

		#self.script_dir = os.path.dirname(__file__)

    def send_command(self):
        type = "YOPYOP"
        playload = self.statut
        Convert_json.convert_json((type, playload))
        
while True:
	if __name__ == "__main__":
    	root = tk.Tk()
    	app = CommandSenderApp(root)
    	root.mainloop()
    print(boucle)
