# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | **Français** | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Visionneuse Windows x86 native des rapports MediaInfo.dll. Chaque fichier dispose de son propre onglet en
lecture seule.

[Compilation et compatibilité](#compilation) | [Audit des dépendances](#dépendances) | [Licence](../license.txt)

## Compilation

Ouvrez MediaInfo.sln dans Visual Studio 2015 avec le jeu d'outils Visual C++ v140 installé. Choisissez Release | Win32 et construisez la solution. La seule plate-forme d'application est Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, lié statiquement,
BSD-3-Clause. [license.txt](../license.txt). [Code source](../MediaInfo/PCRE2/).
PCRE2 est intégrée à l’exécutable et ne nécessite ni DLL distincte ni installation supplémentaire.

Sorties :

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Le visualiseur ne lie pas le runtime C ou C++ et n'a pas besoin d'un redistribuable MSVC. Le MediaInfo.dll
sélectionné peut avoir ses propres dépendances.

La construction nécessite Windows PowerShell et .NET Framework. Il s'agit uniquement d'exigences de
construction ; l'exécutable natif ne nécessite ni PowerShell ni .NET.

### Paquet de distribution

Après avoir construit Release, exécutez
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . Le script crée
`MediaInfo-<version>-win32.zip` dans le répertoire de la solution, en utilisant la version du fichier
exécutable en quatre parties. L'archive contient `MediaInfo.exe` et le `license.txt` combiné directement à sa
racine.

## Compatibilité

La visionneuse Win32 est conçue pour utiliser Windows NT 4.0 APIs.

L'exécutable comprend trois bibliothèques x86 MediaInfo : 26.10 pour le Windows actuel, 21.03 du package
Windows XP et 0.7.60 du package Windows 95–2000. L'architecture d'une bibliothèque ne détermine pas à elle
seule sa compatibilité avec le système d'exploitation. Le visualiseur essaie les bibliothèques groupées de la
plus récente à la plus ancienne et s'arrête après la première requête de chargement et de version réussie.

Windows 95 n'est actuellement pas un moteur d'exécution pris en charge.

## Utilisation

- Fichier > Ouvrir (Ctrl+O) ouvre la boîte de dialogue du fichier Windows avec sélection multiple. Sur Windows
  Vista et versions ultérieures, Ouvrir et Enregistrer utilisent la boîte de dialogue d'élément commun moderne
  ; les anciens Windows utilisent les boîtes de dialogue communes héritées.
- Déposez un ou plusieurs fichiers dans la fenêtre, sur l’icône de l’EXE ou sur son raccourci, ou transmettez
  leurs chemins en ligne de commande. Si les instances multiples sont désactivées, les fichiers s’ouvrent dans
  la fenêtre déjà active.
- Chaque chemin complet normalisé distinct comporte un onglet. La réouverture d'un fichier déjà ouvert
  sélectionne son onglet existant sans recharger ni modifier son rapport, sa sélection ou sa position de
  défilement. Les comparaisons ignorent la casse des lettres de chemin. Les ouvertures de fichiers multiples
  traitent la liste dans l'ordre et laissent actif le dernier fichier traité avec succès, qu'il soit
  nouvellement ouvert ou déjà ouvert. Le survol d'un en-tête d'onglet affiche le chemin complet du fichier
  dans une info-bulle native, y compris lorsque le nom de fichier affiché est raccourci.
- Le menu Fichier répertorie les huit fichiers chargés les plus récemment directement au-dessus de Quitter,
  entre séparateurs. Les entrées affichent uniquement un numéro et un nom de fichier. La sélection d'une
  entrée ouvre son chemin complet stocké ou sélectionne son onglet existant ; une réouverture réussie le
  déplace vers le haut sans doublons. La sélection d'un fichier indisponible demande s'il faut supprimer son
  entrée de fichiers récents. L'icône de question native et les boutons Yes/No sont utilisés. Oui est la
  valeur par défaut et supprime l'entrée du menu et du registre ; Non, il le retient. L'invite inclut le
  chemin complet.
- La molette de la souris sur les en-têtes d'onglets débordants fait défiler la bande d'en-tête d'un onglet
  par message sans modifier la sélection ou le focus.
- Onglets de commutation Ctrl+Tab et Ctrl+Maj+Tab ; Ctrl+W ferme l'onglet actif. Un clic central sur l'en-tête
  d'un onglet ferme cet onglet tout en préservant tout autre onglet actif. Fichier > Fermer tout ferme tous
  les onglets, y compris les rapports en file d'attente. Fichier > Quitter (Alt+F4) ferme l'application.
- Un double-clic sélectionne un mot. Un triple-clic sélectionne une ligne logique. Le glisser étend la
  sélection par mots ou lignes.
- Ctrl+A sélectionne le rapport ; Ctrl+C le copie.
- Édition > Rechercher (Ctrl+F) effectue une recherche dans l’onglet actif. F3 répète la recherche ; Maj+F3
  inverse son sens. Aux extrémités du texte, la recherche reprend à l’autre extrémité. Options > Retour
  automatique à la ligne concerne uniquement l’onglet actif ; la coche suit l’onglet sélectionné. La fenêtre
  de recherche peut être réduite et redimensionnée horizontalement ; sa position et l’option Toujours au
  premier plan sont mémorisées. Jusqu’à 30 recherches et leurs options sont conservées uniquement jusqu’à la
  fermeture de l’application. Les options de début et de fin s’appliquent aux lignes logiques. Les expressions
  régulières utilisent la syntaxe PCRE2. Toutes les commandes du menu Édition concernent uniquement l’onglet
  actif. Entrée lance la recherche ; Maj+Entrée inverse le sens choisi. « Respecter la casse » distingue les
  majuscules des minuscules ; « Rechercher vers l’arrière » recherche vers le début du texte. Choisir une
  entrée de l’historique rétablit les cinq options de recherche, y compris l’état du mode d’expression
  régulière ; « Toujours au premier plan » est indépendante. « Expression régulière » désactive « La ligne
  commence par » et « La ligne se termine par ». Si les deux options de début et de fin de ligne sont
  activées, une correspondance à l’une des extrémités suffit. « Retour automatique à la ligne » modifie
  uniquement l’affichage.
- Options > Préférences (Ctrl+G) ouvre une boîte de dialogue de préférences unique pour les chemins MediaInfo
  et curl, la police du rapport, l'anticrénelage des polices, la langue de l'interface et la langue du
  rapport. Un chemin DLL vide permet la découverte automatique.
- Le bouton de police affiche la famille, la taille en points et le style et ouvre la boîte de dialogue de
  police standard Windows. La valeur par défaut restaure Consolas ou Courier New si Consolas n'est pas
  disponible ; le bouton Par défaut est désactivé lorsque la valeur par défaut est sélectionnée. Les polices
  sélectionnées par l'utilisateur sont conservées sans substitution par le code de l'application.
- Les choix d'anticrénelage de police sont ClearType lorsqu'ils sont pris en charge, GDI et Aucun. Le choix
  initial est ClearType lorsqu'il est pris en charge, sinon GDI. Les paramètres de police affectent uniquement
  les rapports multimédias et leurs exportations d'images.
- L'aide ouvre une fenêtre non modale distincte avec sa propre entrée dans la barre des tâches et son propre
  bouton de réduction. À propos est une boîte de dialogue modale ; son en-tête de produit répertorie les trois
  versions DLL intégrées.

Imprimer… (Ctrl+P) ouvre la boîte de dialogue système des imprimantes et imprime tout l’onglet actif sans
aperçu. La police du rapport est utilisée ; les longues lignes sont renvoyées à la ligne et le texte est
réparti sur plusieurs pages. L’impression s’exécute en arrière-plan.

Ouvrir un dossier… ouvre les fichiers directement contenus dans le dossier sélectionné, chacun dans son propre
onglet. Les sous-dossiers ne sont pas inclus. Ouvrir et Ouvrir un dossier partagent le dernier dossier
sélectionné. L’export mémorise son propre dossier, Documents par défaut.

Le mode avancé affiche des champs supplémentaires dans le rapport.

Analyse complète examine l'intégralité du fichier et peut prendre plus de temps. Ces options de rapport et
Niveau de trace appartiennent à chaque onglet ; une modification actualise uniquement l’onglet actif. La
dernière combinaison choisie manuellement est enregistrée pour les nouveaux onglets et le prochain lancement.
Un rapport mis en cache correspondant est réutilisé tant que le fichier reste inchangé.

Formats connus, Codecs connus et Paramètres connus s’ouvrent dans leurs propres onglets de rapport.

La taille et l'emplacement initiaux de la fenêtre sont sélectionnés par Windows. Le placement des fenêtres
précédemment enregistré remplace ces valeurs par défaut lors des lancements ultérieurs.

La partie gauche de la barre d’état affiche les chemins des fichiers et la progression du chargement ; la
partie droite affiche la version de MediaInfo.dll chargée. Les chemins trop longs sont abrégés par des points
de suspension selon l’espace disponible.

## Créer un fichier d’en-tête

Le menu Outils est le quatrième menu de la barre de menus. Sa commande Créer un fichier d’en-tête… ouvre un
fichier source indépendamment des onglets du rapport et copie ses 524288 premiers octets (512 KiB). Un fichier
plus court est copié dans son intégralité ; un fichier vide produit une sortie vide. Il s'agit d'une lecture
de fichier binaire ordinaire, sans analyse MediaInfo ni nécessité de MediaInfo.dll. L’outil ne modifie ni les
onglets des rapports ni la liste des fichiers récents du programme.

Après la lecture, la boîte de dialogue Enregistrer sous démarre dans le dossier du fichier source et suggère
video.mp4.header pour video.mp4 : .header est ajouté au nom d'origine complet. Vous pouvez modifier à la fois
le nom et le dossier de destination. L'annulation de l'une ou l'autre boîte de dialogue n'écrit aucune sortie.
Le remplacement d'une destination existante nécessite une confirmation. Le fichier source reste inchangé ; un
échec d’enregistrement préserve le fichier de destination existant. L’ouverture et l’enregistrement utilisent
les boîtes de dialogue système les plus récentes disponibles sur cette version de Windows.

Au démarrage de l'application, l'outil prend son dossier d'entrée initial depuis Fichier > Ouvrir. Si aucun
dossier n'a été enregistré, Windows choisit l'emplacement initial. Une fois qu'un fichier d'entrée est
sélectionné, l'outil mémorise son propre dossier uniquement jusqu'à ce que l'application se ferme, même si la
boîte de dialogue Enregistrer sous est annulée. Il ne modifie pas les dossiers utilisés par Ouvrir et Exporter
et n'enregistre pas non plus son propre dossier dans les paramètres de l'application. Chaque boîte de dialogue
Enregistrer sous démarre dans le dossier du fichier d'entrée actuellement sélectionné, quelle que soit la
destination de sauvegarde précédente.

## Recherche des bibliothèques

Un chemin manuel enregistré est essayé en premier. S'il ne peut pas être chargé, la découverte automatique
tente :

1. MediaInfo.dll à côté de l'exécutable, puis dans chaque répertoire parent jusqu'au lecteur ou à la racine du
   partage UNC.
2. ProgramFiles, ProgramFiles(x86) et ProgramW6432.
3. LOCALAPPDATA et APPDATA.

Sous ces racines d'installation, la découverte vérifie MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Les emplacements illisibles et les
DLLs incompatibles sont ignorés. Il n'analyse pas le disque de manière récursive.

Si aucun DLL externe compatible n'est trouvé, le visualiseur essaie les versions intégrées dans cet ordre :
26.10, 21.03, 0.7.60. Il extrait et teste une version à la fois. Une fois qu'une version est chargée avec
succès, les anciennes versions ne sont ni extraites ni testées. La distribution de MediaInfo.exe seule est
suffisante ; un DLL externe compatible est toujours prioritaire et peut être mis à jour indépendamment.

Un changement manuel de bibliothèque ayant échoué conserve la bibliothèque déjà chargée.

## Exportation du rapport

Les formats Enregistrer sous sont classés TXT, BMP, GIF, JPEG, PNG, TIFF et WebP. Les encodeurs non pris en
charge sont omis des boîtes de dialogue modernes et héritées.

TXT propose ANSI, UTF-8, UTF-8 avec BOM, UTF-16 BE avec BOM et UTF-16 LE avec BOM. La deuxième entrée, UTF-8
sans BOM, est sélectionnée par défaut. Le texte intégral du rapport et ses fins de ligne d’origine sont
conservés.

BMP, PNG et TIFF préservent toutes les couleurs rendues ; GIF89a préserve la palette exacte du rendu lorsque
l'image contient au plus 256 couleurs. L'exportation écrit toujours le format sélectionné ou signale une
erreur ; il ne remplace jamais un autre format.

## Langues de l’interface et des rapports

Les préférences (Options > Préférences, Ctrl+G) regroupent les chemins des bibliothèques, la police du
rapport, le lissage et les langues. L’interface possède 36 variantes et suit initialement Windows. Les
rapports utilisent toujours l’anglais d’origine de la bibliothèque, indépendamment de Windows et de
l’interface. Seul un choix manuel change leur langue : anglais, 37 traductions ou une table CSV MediaInfo
personnelle.

OK ou Appliquer valide les modifications ; Annuler abandonne les modifications en attente. Les préférences
permettent de limiter les noms d’onglets (80 par défaut) et d’effacer la liste des fichiers récents. Les noms
longs conservent le début, la fin et l’extension avec des points de suspension au milieu.

Par défaut, une seule instance est autorisée et les lancements suivants transmettent les fichiers à la fenêtre
ouverte. Les préférences permettent d’autoriser plusieurs instances. Si plusieurs fenêtres sont autorisées,
seule la première de chaque formulaire retrouve sa position enregistrée ; les suivantes ne reprennent que la
taille.

La modification uniquement de l'interface laisse inchangé le texte des rapports ouverts. Un changement de
langue de rapport appliqué manuellement recharge leurs rapports tout en préservant l’ordre des tabulations et
l’ordre MRU.

## libcurl

Vérifications automatiques de la découverte curl à côté du MediaInfo DLL sélectionné, puis du
executable/ancestor partagé, des fichiers programme et des emplacements d'installation utilisateur. Si aucun
curl externe compatible n'est trouvé, la version actuelle intégrée ou XP correspondante est extraite dans le
cache vérifié par utilisateur. Le plus ancien MediaInfo 0.7.60 contourne entièrement la découverte,
l'extraction et le chargement de curl. Un curl non valide explicitement sélectionné rejette le changement de
préférence ; l'absence du curl automatique facultatif n'empêche pas les rapports de fichiers locaux
ordinaires.

## Noms de fichiers et fichiers récents

Les noms de fichiers MRU ne sont raccourcis que lorsqu’ils sont plus longs que les unités de code 80 UTF-16.
Des points de suspension au milieu préservent le début, la fin du nom de fichier avant son extension et
l'extension finale complète ; les chemins complets et les rapports restent inchangés. Les légendes des onglets
utilisent le même algorithme avec une limite par défaut configurable de 80.

Fichiers récents > Effacer efface immédiatement à la fois le menu MRU en direct et ses chemins enregistrés
tout en laissant tous les onglets ouverts intacts. Il n'applique ni ne valide les préférences en attente et
n'active pas Appliquer. Annuler ou Échapper préserve l'historique effacé tout en supprimant les modifications
en attente. Clear est désactivé chaque fois que la liste est vide et son état est actualisé lorsque de
nouveaux rapports remplissent la liste. Un échec d’écriture dans le registre est immédiatement signalé.
L'application d'une nouvelle limite de nom d'onglet met à jour chaque onglet ouvert sans recharger son rapport
multimédia.

## Licence et redistribution

Le téléspectateur est sous licence MIT en license.txt.

MediaInfo est un composant tiers. Le seul avis de distribution maintenu est la racine license.txt, codée comme
UTF-8 avec CRLF et comprenant la visionneuse, les bibliothèques, les composants incorporés statiquement,
l'icône et les tables de traduction officielles.

Ce produit utilise la bibliothèque MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licence : <https://mediaarea.net/en/MediaInfo/License>
- Windows téléchargements : <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Dépendances

### Fichiers

| Ressource | Architecture | Version rapportée par le composant | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Les chemins du tableau sont relatifs au dossier du projet MediaInfo.

La bibliothèque actuelle rapporte une version de développement ; sa source exacte commit ne peut pas être
récupérée à partir de cette chaîne de version. La notice qui l'accompagne utilise le texte de droit d'auteur
et d'autorisation 8.11.0 en amont, dont les conditions de licence sont également présentes dans la série de
développement.

### Composants incorporés

| Composant | Preuve et portée | Avis |
| --- | --- | --- |
| MediaInfoLib | Versions actuelles et exportations Unicode requises ; binaires fournis inchangés | Copyright original spécifique à la version, conditions de redistribution et clause de non-responsabilité |
| ZenLib | Références de projet statiques et ZenLib RTTI intégré dans les trois DLLs ; révisions liées exactes non fournies | Avis ZenLib de style zlib |
| zlib | Chaînes de version inflate/deflate intégrées : 1.3.2 dans MediaInfo 26.10, 1.2.11 dans 21.03, 1.2.7 dans 0.7.60 ; curl signale en outre 1.3.1 et 1.2.8 | Avis zlib originaux pour les cinq versions |
| TinyXML-2 | Correspondance des cibles sources modernes et du binaire RTTI ; inclus dans le projet hérité, mais non identifié de manière indépendante dans le binaire hérité supprimé | Avis original de style Lee Thomason zlib conservé |
| Brian Gladman AES | Inclus dans les deux cibles de bibliothèques modernes en amont, avec des avis de source permissifs correspondants | Avis de redistribution et clause de non-responsabilité 1998–2013 |
| Brian Gladman SHA-1/SHA-2 | Les deux cibles modernes ; Tables constantes SHA-256 et SHA-512 présentes dans les deux binaires modernes | Avis de redistribution et clause de non-responsabilité 1998–2010 |
| Brian Gladman HMAC | Les deux cibles modernes et leur code de lecteur curl/S3 | Avis original de trois conditions, y compris son paragraphe de licence alternative |
| MD5 | Cibles sources modernes ; La mise en œuvre de Colin Plumb indique explicitement le domaine public | Attribution conservée |
| Base64 | En-tête Markus Ewald dans les trois arborescences sources correspondantes, créditant Bob Withers | Attribution de la paternité originale conservée ; qualification ci-dessous |
| fmt | 26.10 cible et fmt v11 format_error RTTI dans le binaire | Avis MIT original, y compris une exception facultative |
| tfsxml | 26.10 source cible | Avis original MediaArea MIT |
| Interface Android JNI | JNI_OnLoad est en fait exporté par les deux DLLs modernes ; l'en-tête JNI inclus provient de AOSP | AOSP copyright et licence Apache complète 2.0 |
| libcurl | Fichiers binaires x86 fournis ; exportations de la version actuelle ; utilisé dynamiquement par le MediaInfo moderne | Avis curl originaux pour 8.11.0 et 7.47.1 |
| Traductions officielles des rapports | Toutes les sources CSV non modifiées 38 du répertoire de langues MediaInfo v26.10 ; Les tableaux 37 non anglais sont intégrés, tandis que l'anglais utilise les valeurs par défaut DLL | Même projet Avis BSD-2-Clause retenu dans l'avis combiné |
| Icône MediaInfo | Icône multi-images officielle non modifiée, révision source f057dd3649bc8692a83863b67770e22c9b9dd81a | Avis original BSD-2-Clause et attribution |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Les cibles sources correspondantes établissent l’inclusion dans ces configurations de build en amont ; ils ne
prouvent pas que chaque fonction survit à l'optimisation dans les binaires du fournisseur. Aucune réclamation
de version exacte n'est faite pour les dépendances dont la révision n'est pas enregistrée dans ces binaires.

### Composants facultatifs et bibliothèques système

- Les projets de bibliothèque Windows activent libcurl chargé au moment de l'exécution pour MediaInfo 26.10 et
  21.03. MediaInfo 0.7.60 a été construit avec MEDIAINFO_LIBCURL_NO ; son binaire contient également le
  diagnostic de support désactivé. Le spectateur ne découvre, n'extrait ou ne charge jamais curl pour cette
  version groupée.
- libmms est désactivé dans les trois Windows DLLs fournis, comme le confirment leurs messages de support
  désactivés intégrés. Il n'est pas redistribué.
- Qt et wxWidgets appartiennent aux versions facultatives GUI. Ni l'un ni l'autre n'est inclus dans cette
  visionneuse ni dans ces dépendances DLL. Leurs entrées génériques ont été supprimées de la licence affichée.
- Graphviz est un hook d'exécution facultatif dans le code en amont moderne. Aucun Graphviz DLL n’est
  redistribué.
- Aucun plugin FFmpeg n'est redistribué.
- Le MediaInfo DLLs importe directement uniquement KERNEL32.dll. Cela ne signifie pas que leur environnement
  d'exécution et leur code d'assistance liés statiquement sont absents.
- Le curl actuel importe directement WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll et KERNEL32.dll. XP
  curl importe directement WS2_32.dll, WLDAP32.dll, ADVAPI32.dll et KERNEL32.dll. Ce sont des composants
  Windows. Leur disponibilité est vérifiée par le chargeur Windows.
- Curl rapporte Windows Schannel/WinSSL, pas une version OpenSSL. Sa dépendance de compression supplémentaire
  signalée est incluse statiquement zlib. Aucun DLL externe non-Windows supplémentaire n'apparaît dans son
  tableau d'importation directe.
- Le visualiseur lui-même n'a pas de dépendance d'exécution C/C++. Le DLLs tiers fourni contient ses propres
  parties d'exécution compilées. Les versions Windows utilisent les outils Microsoft ; il n'existe aucune
  preuve exigeant les entrées d'inventaire génériques libstdc++ ou libc++.
- JPEG utilise le système chargé dynamiquement GDI+. Le packer de ressources C# et PowerShell sont des outils
  de construction et ne sont pas des dépendances d'exécution.

L’inspection ordinaire des fichiers locaux ne nécessite pas de serveur MediaArea ni de base de données de
format téléchargée à distance. libcurl est utilisé par MediaInfo pour les entrées URL et les références
potentiellement distantes dans les formats multimédias pris en charge. Le regrouper n’ajoute pas de commande
d’ouverture URL distincte à cette visionneuse.

### Stockage des licences et limitations

Le seul avis de distribution conservé est [license.txt](../license.txt) , codé comme UTF-8 avec CRLF. Les
clauses de redistribution BSD, curl, zlib, MIT et Apache vérifiées ne nécessitent pas de fichier de
notification distinct physiquement à côté de chaque DLL ; l'avis combiné les accompagne dans les documents
exécutables et de distribution.

Le package MediaInfo 0.7.60 archivé utilise sa propre licence spécifique à la version et inclut l'ancien texte
GNU Library GPL. Ses termes distinguent expressément la redistribution binaire non modifiée des versions
modifiées ; la liaison dynamique par cette visionneuse ne modifie pas le DLL fourni. Ses conditions originales
et le texte de licence qui l'accompagne sont conservés. Le spectateur reste sous licence MIT.

Une attribution en amont doit être qualifiée : l'en-tête Markus Ewald Base64 n'a aucune autorisation explicite
ni déclaration de licence. MediaArea décrit l'implémentation Bob Withers Base64 comme domaine public dans sa
documentation MediaConch associée, mais cela n'établit pas indépendamment une concession de licence pour
chaque modification d'Ewald. Aucune concession de licence n'a été inventée pour cet en-tête. Une confirmation
complète du fournisseur de cette provenance, les révisions exactes ZenLib et le développement curl commit
n'étaient pas disponibles dans les binaires fournis. Ces points empêchent de traiter cet inventaire comme un
SBOM complet et certifié de manière indépendante.

### Sources primaires

- [Conditions de redistribution MediaInfo](https://mediaarea.net/en/MediaInfo/License)
- 
  [Cible de la bibliothèque MediaInfo 26.10](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [Cible de la bibliothèque MediaInfo 21.03](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [Cible de la bibliothèque MediaInfo 0.7.60](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Chargeur d'exécution curl](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Sources d'aide groupées et leurs notifications](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [Avis ZenLib](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [Avis de source zlib](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 avis](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 avis](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licence Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 description](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Les tableaux de rapport proviennent de
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . Le projet correspondant
LICENSE est <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
