# Huffman
Huffman file compressor

Guide d'utilisation
==============


I- Lancement du logiciel
==============

 

Voici ce que vous obtenez lors de l'ouverture du dossier Huffman : 

![1](https://cdn.discordapp.com/attachments/754976677808832512/786987460298145813/unknown.png)

 

 

Dans un premier temps, veuillez choisir le texte que vous souhaitez compresser. Ouvrez ensuite le fichier input (présenté ci-dessus) et inscrivez-y votre texte. Ici, nous avons pris comme exemple “Efrei” : 

![2](https://cdn.discordapp.com/attachments/754976677808832512/786987484307128350/unknown.png)
 

 

Enfin, pour lancer le logiciel, il vous suffit de lancez « Huffman.exe », ou bien d’exécuter le fichier main.c dans votre IDE préféré. 

 

Après ouverture, le logiciel se présente comme ceci : 

![3](https://cdn.discordapp.com/attachments/754976677808832512/786987515273019432/unknown.png)

 

II- Utilisations
==============

 

Trois choix d’utilisation se présenteront à vous. Selon vos besoins saisissez la commande 1, 2 ou 3 : 

- Pour une compression : 1 
- Pour une décompression : 2 
- Pour fermer le programme : 3 

 

1- Compression d’un fichier texte choisi par l’utilisateur : 
-------------------------------------------------------------
 

En choisissant la commande 1, vous obtiendrez alors votre texte compressé, provenant du fichier "input.txt" rempli au préalable, encodé dans le fichier nommé "Huffman.txt" : 

![4](https://cdn.discordapp.com/attachments/754976677808832512/786988636359884850/unknown.png)
![5](https://cdn.discordapp.com/attachments/754976677808832512/786987566632534036/unknown.png)

Votre texte est à ce stade compressé, son taux de compression s’affiche en % (la place que prend le code binaire du fichier par rapport à avant, ici 30%, soit 70% de gain de place), son code binaire l’est en tout cas, et un fichier "dico.txt" a été généré. Ce dernier va permettre la décompression, comme ci-dessous : 

 

2- Décompression d’un fichier texte  
-------------------------------------------------------------
 

La commande 2 vous permettra d'obtenir la clés de la décompression de votre fichier. Bien sûr, si vous n’avez pas compressé votre fichier au préalable, ou si vous avez effectué une quelconque modification dans un des fichier .txt, cela ne marchera pas correctement. 

 
![6](https://cdn.discordapp.com/attachments/754976677808832512/786987587800793148/unknown.png)
 

Ainsi, vous obtiendrez le fichier décompressé dans "output.txt", et le logiciel vous rouvre le dico comme ceci : 

![7](https://cdn.discordapp.com/attachments/754976677808832512/786987609972408340/unknown.png) 

 

Pour vous ouvrir le fichier décompresser, il suffit de suivre l’étape suivante :  

 

3- fermeture du logiciel 
-------------------------------------------------------------
 

En choisissant la commande 3, votre fichier décompressé apparaîtra et le logiciel se  
fermera : 

 ![8](https://cdn.discordapp.com/attachments/754976677808832512/786987632361865246/unknown.png)
 ![9](https://cdn.discordapp.com/attachments/754976677808832512/786987658190389309/unknown.png)
 

Par ailleurs, si vous souhaitez obtenir le code binaire de votre texte (non-compressé), il vous suffit de vous rendre dans le fichier "binary.txt" : 

 ![10](https://cdn.discordapp.com/attachments/754976677808832512/786987679522095194/unknown.png)

 

Ainsi, résumons : 

- Le fichier **input** doit comprendre votre texte à compresser 
- Le fichier **binary** correspond au code binaire du texte 
- Le fichier **dico** stock le dictionnaire permettant la décompression 
- Le fichier **huffman** présente le code compressé du texte selon le principe Huffman  
- Le fichier **output** comprend le texte décompressé 

 

# Nous vous souhaitons une bonne utilisation ! 
