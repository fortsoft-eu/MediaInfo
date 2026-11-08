# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | **Español** | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Visor nativo de Windows x86 para informes de MediaInfo.dll. Cada archivo tiene su propia pestaña de solo
lectura.

[Compilación y compatibilidad](#compilación) | [Auditoría de dependencias](#dependencias) | [Licencia](../license.txt)

## Compilación

Abra MediaInfo.sln en Visual Studio 2015 con el conjunto de herramientas Visual C++ v140 instalado. Elija Release | Win32 y cree la solución. La única plataforma de aplicación es Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, enlace estático, BSD-3-Clause.
[license.txt](../license.txt). [Código fuente](../MediaInfo/PCRE2/).
PCRE2 está integrada en el ejecutable y no requiere una DLL independiente ni una instalación adicional.

Salidas:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

El visor no vincula el tiempo de ejecución C o C++ y no necesita un MSVC redistribuible. El MediaInfo.dll
seleccionado puede tener sus propias dependencias.

El edificio requiere Windows PowerShell y .NET Framework. Estos son sólo requisitos de construcción; el
ejecutable nativo no requiere ni PowerShell ni .NET.

### Paquete de distribución

Después de compilar Release, ejecute
`powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1` . El script crea
`MediaInfo-<version>-win32.zip` en el directorio de la solución, utilizando la versión del archivo de cuatro
partes del ejecutable. El archivo contiene `MediaInfo.exe` y el `license.txt` combinado directamente en su
raíz.

## Compatibilidad

El visor Win32 está diseñado para utilizar Windows NT 4.0 APIs.

El ejecutable incluye tres bibliotecas x86 MediaInfo: 26.10 para el Windows actual, 21.03 del paquete Windows
XP y 0.7.60 del paquete Windows 95–2000. La arquitectura de una biblioteca por sí sola no determina su
compatibilidad con el sistema operativo. El visor prueba las bibliotecas empaquetadas, desde la más nueva
hasta la más antigua, y se detiene después de la primera carga y consulta de versión exitosas.

Windows 95 no es actualmente un tiempo de ejecución compatible.

## Uso

- Archivo > Abrir (Ctrl+O) abre el cuadro de diálogo del archivo Windows con selección múltiple. En Windows
  Vista y posteriores, Abrir y Guardar utiliza el moderno cuadro de diálogo de elementos comunes; Los Windows
  más antiguos utilizan los cuadros de diálogo comunes heredados.
- Arrastre uno o varios archivos a la ventana, al icono del EXE o a su acceso directo, o indique sus rutas en
  la línea de comandos. Si no se permiten varias instancias, los archivos se abren en la ventana que ya está
  en ejecución.
- Cada ruta completa normalizada distinta tiene una pestaña. Al volver a abrir un archivo ya abierto, se
  selecciona su pestaña existente sin recargar ni cambiar su informe, selección o posición de desplazamiento.
  Las comparaciones ignoran las mayúsculas y minúsculas de la ruta. Las aperturas de varios archivos procesan
  la lista en orden y dejan activo el último archivo procesado exitosamente, ya sea abierto recientemente o ya
  abierto. Al pasar el cursor sobre el encabezado de una pestaña, se muestra la ruta completa del archivo en
  una información sobre herramientas nativa, incluso cuando el nombre del archivo mostrado está acortado.
- El menú Archivo enumera los ocho archivos cargados más recientemente directamente encima de Salir, entre
  separadores. Las entradas muestran sólo un número y un nombre de archivo. Al seleccionar una entrada, se
  abre su ruta completa almacenada o se selecciona su pestaña existente; una reapertura exitosa lo lleva a la
  cima sin duplicados. Al seleccionar un archivo no disponible se le preguntará si desea eliminar su entrada
  de archivos recientes. Se utilizan el ícono de pregunta nativa y los botones Yes/No. Sí es el valor
  predeterminado y elimina la entrada del menú y del registro; No lo retiene. El mensaje incluye la ruta
  completa.
- La rueda del mouse sobre los encabezados de pestañas desbordados desplaza la tira del encabezado una pestaña
  por mensaje sin cambiar la selección o el enfoque.
- Ctrl+Tab y Ctrl+Mayús+Tab cambian las pestañas; Ctrl+W cierra la pestaña activa. Al hacer clic con el botón
  central en el encabezado de una pestaña, se cierra esa pestaña y se conserva cualquier otra pestaña activa.
  Archivo > Cerrar todo cierra todas las pestañas, incluidos los informes en cola. Archivo > Salir (Alt+F4)
  cierra la aplicación.
- El menú contextual de la cabecera de una pestaña incluye Cerrar pestaña. Active Cerrar pestañas con
  doble clic en Preferencias para cerrar una pestaña haciendo doble clic en su cabecera. La opción está
  desactivada de forma predeterminada y se guarda.
- Un doble clic en el texto del informe selecciona una palabra. Un triple clic selecciona una línea
  lógica. Arrastrar amplía la selección por palabras o líneas.
- Ctrl+A selecciona el informe; Ctrl+C lo copia.
- Edición > Buscar (Ctrl+F) busca en la pestaña de informe activa o en el área de texto de Ayuda o
  Acerca de, según la ventana que tenga el foco. La ventana de búsqueda conserva el último origen
  seleccionado mientras tiene el foco. F3 repite la búsqueda; Mayús+F3 invierte su dirección. Al llegar
  a un extremo del texto, la búsqueda continúa desde el otro. Opciones > Ajuste de línea solo afecta a
  la pestaña activa; la marca cambia según la pestaña seleccionada. La ventana de búsqueda se puede
  minimizar y redimensionar horizontalmente; se recuerdan su posición y la opción Siempre visible. Se
  conservan hasta 30 búsquedas y sus opciones solo hasta que se cierra la aplicación. Las opciones de
  principio y final se aplican a las líneas lógicas. Las expresiones regulares usan la sintaxis de
  PCRE2. Los demás comandos del menú Edición se aplican a la pestaña de informe activa. Entrar inicia la
  búsqueda; Mayús+Entrar invierte la dirección elegida. «Coincidir mayúsculas y minúsculas» distingue
  mayúsculas y minúsculas; «Buscar hacia atrás» busca hacia el principio del texto. Elegir una entrada
  del historial restaura las cinco opciones de búsqueda, incluido el estado del modo de expresión
  regular; «Siempre visible» es independiente. «Expresión regular» desactiva «La línea empieza por» y
  «La línea termina en». Si ambas opciones de extremos de línea están activadas, basta con que coincida
  uno de ellos. «Ajuste de línea» solo cambia la visualización.
- Opciones > Preferencias (Ctrl+G) abre un cuadro de diálogo de preferencias único para las rutas MediaInfo y
  curl, la fuente del informe, el suavizado de fuente, el idioma de la interfaz y el idioma del informe. Una
  ruta DLL vacía permite el descubrimiento automático.
- El botón de fuente muestra la familia, el tamaño en puntos y el estilo y abre el cuadro de diálogo de fuente
  estándar Windows. El valor predeterminado restaura Consolas o Courier New si Consolas no está disponible; el
  botón Predeterminado está deshabilitado mientras se selecciona el valor predeterminado. Las fuentes
  seleccionadas por el usuario se conservan sin sustitución por el código de la aplicación.
- Las opciones de suavizado de fuentes son ClearType cuando se admiten, GDI y Ninguna. La elección
  inicial es ClearType cuando sea compatible; en caso contrario, GDI. Los ajustes de fuente afectan a
  las pestañas de informes, sus exportaciones a imagen y su impresión. Ayuda y Acerca de conservan sus
  propias fuentes de texto.
- Ayuda abre una ventana independiente y no modelo con su propia entrada en la barra de tareas y un botón de
  minimizar. Acerca de es un diálogo modal; su encabezado de producto enumera las tres versiones integradas de
  DLL.

Archivo > Configurar página… abre los ajustes de papel, orientación y márgenes para la sesión actual.
Imprimir… (Ctrl+P) abre el diálogo de impresión del sistema; Windows 11 ofrece una vista previa,
mientras que Windows 10 y anteriores conservan el diálogo clásico. Ctrl+P imprime la pestaña activa de
la ventana principal o el área de texto de Ayuda o Acerca de, según la ventana que tenga el foco. Los
informes usan la fuente elegida, Ayuda la fuente de diálogo del sistema y Acerca de la de su área de
texto. Si no hay pestañas abiertas pero Ayuda está abierta, Configurar página… e Imprimir… siguen
disponibles; Imprimir… imprime la Ayuda. Ayuda usa el diálogo de impresión de la ventana principal;
pulsar Ctrl+P de nuevo en Ayuda lo trae al primer plano. Las líneas largas se ajustan y el texto se
divide en páginas. La impresión se realiza en segundo plano.

Abrir carpeta… abre los archivos directamente contenidos en la carpeta seleccionada, cada uno en su propia
pestaña. No se incluyen las subcarpetas. Abrir y Abrir carpeta comparten la última carpeta seleccionada. La
exportación recuerda su propia carpeta, Documentos por defecto.

El modo avanzado muestra campos adicionales en el informe.

Análisis completo examina todo el archivo y puede tardar más. Estas opciones de informe y Nivel de traza
pertenecen a cada pestaña; un cambio actualiza solo la pestaña activa. La última combinación elegida
manualmente se guarda para nuevas pestañas y el próximo inicio. Un informe almacenado en caché coincidente se
reutiliza mientras el archivo permanece sin cambios.

Formatos conocidos, Códecs conocidos y Parámetros conocidos se abren en sus propias pestañas de informe.

El tamaño y la ubicación de la ventana inicial los selecciona Windows. La ubicación de la ventana guardada
previamente anula esos valores predeterminados en lanzamientos posteriores.

La parte izquierda de la barra de estado muestra las rutas de los archivos y el progreso de carga; la derecha
muestra la versión de MediaInfo.dll cargada. Las rutas largas se abrevian con puntos suspensivos según el
espacio disponible.

## Crear archivo de encabezado

El menú Herramientas es el cuarto de la barra de menús. Su comando Crear archivo de encabezado… abre un
archivo de origen independientemente de las pestañas del informe y copia sus primeros 524288 bytes (512 KiB).
Un archivo más corto se copia en su totalidad; un archivo vacío produce una salida vacía. Esta es una lectura
de archivos binarios normal, sin analizar el contenido con MediaInfo ni necesitar MediaInfo.dll. La
herramienta deja sin cambios las pestañas de informes y la lista de archivos recientes del visor.

Después de leer, el cuadro de diálogo Guardar como comienza en la carpeta del archivo de origen y sugiere
video.mp4.header para video.mp4: .header se agrega al nombre original completo. Puede cambiar tanto el nombre
como la carpeta de destino. Cancelar cualquiera de los diálogos no escribe ningún resultado. Reemplazar un
destino existente requiere confirmación. El archivo de origen permanece sin cambios; un guardado fallido
conserva el destino anterior. Para abrir y guardar se utilizan los cuadros de diálogo del sistema más modernos
disponibles en esa versión de Windows.

Al iniciar la aplicación, la herramienta toma su carpeta de entrada inicial de Archivo > Abrir. Si no se ha
guardado ninguna carpeta, Windows elige la ubicación inicial. Después de seleccionar un archivo de entrada, la
herramienta recuerda su propia carpeta sólo hasta que se cierra la aplicación, incluso si se cancela Guardar
como. No cambia las carpetas utilizadas por Abrir y Exportar ni guarda su propia carpeta en la configuración
de la aplicación. Cada cuadro de diálogo Guardar como comienza en la carpeta del archivo de entrada
seleccionado actualmente, independientemente del destino de guardado anterior.

## Búsqueda de bibliotecas

Primero se prueba una ruta manual guardada. Si no se puede cargar, el descubrimiento automático intenta:

1. MediaInfo.dll al lado del ejecutable, luego en cada directorio principal hasta la unidad o UNC comparte
   raíz.
2. ProgramFiles, ProgramFiles(x86) y ProgramW6432.
3. LOCALAPPDATA y APPDATA.

Bajo estas raíces de instalación, el descubrimiento comprueba MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Se omiten las ubicaciones ilegibles
y DLLs incompatibles. No escanea recursivamente el disco.

Si no se encuentra ningún DLL externo compatible, el espectador prueba las versiones integradas en este orden:
26.10, 21.03, 0.7.60. Extrae y prueba una versión a la vez. Una vez que una versión se carga correctamente,
las versiones anteriores no se extraen ni se prueban. Distribuir MediaInfo.exe por sí solo es suficiente; un
DLL externo compatible siempre tiene prioridad y se puede actualizar de forma independiente.

Un cambio manual fallido de biblioteca retiene la biblioteca que ya estaba cargada.

## Exportación de informes

Los formatos Guardar como se ordenan TXT, BMP, GIF, JPEG, PNG, TIFF y WebP. Los codificadores no compatibles
se omiten en los cuadros de diálogo modernos y heredados.

TXT ofrece ANSI, UTF-8, UTF-8 con BOM, UTF-16 BE con BOM y UTF-16 LE con BOM. La segunda opción, UTF-8 sin
BOM, es la predeterminada. Se conservan el texto completo del informe y sus finales de línea originales.

BMP, PNG y TIFF conservan todos los colores renderizados; GIF89a conserva la paleta renderizada exacta cuando
la imagen tiene como máximo 256 colores. Exportar siempre escribe el formato seleccionado o informa un error;
nunca sustituye a otro formato.

## Idiomas de interfaz y de informes

Las preferencias (Opciones > Preferencias, Ctrl+G) contienen rutas de bibliotecas, fuente del informe,
suavizado e idiomas. La interfaz ofrece 36 variantes y sigue inicialmente a Windows. Los informes usan siempre
el inglés original de la biblioteca, independientemente de Windows y de la interfaz. Solo una selección manual
cambia su idioma: inglés, 37 traducciones o una tabla CSV de MediaInfo propia.

Aceptar o Aplicar confirma los cambios; Cancelar descarta los pendientes. Las preferencias permiten limitar
los nombres de pestaña (80 por defecto) y borrar la lista de archivos recientes. Los nombres largos conservan
el principio, el final y la extensión con puntos suspensivos en medio.

De forma predeterminada, solo se permite una instancia y los siguientes inicios envían los archivos a la
ventana abierta. En Preferencias se pueden permitir varias instancias. Si hay varias ventanas, solo la primera
de cada formulario recupera su posición guardada; las siguientes recuperan únicamente el tamaño.

Al cambiar solo la interfaz, el texto de los informes abiertos no se modifica. Un cambio de idioma de informe
aplicado manualmente recarga sus informes manteniendo el orden de tabulación y el orden MRU.

## libcurl

El descubrimiento automático de curl verifica junto al MediaInfo DLL seleccionado, luego el
executable/ancestor compartido, los archivos de programa y las ubicaciones de instalación del usuario. Si no
se encuentra ningún curl externo compatible, la versión integrada actual o XP coincidente se extrae en la
caché por usuario verificada. El MediaInfo 0.7.60 más antiguo omite por completo el descubrimiento, la
extracción y la carga de curl. Un curl no válido seleccionado explícitamente rechaza el cambio de preferencia;
La falta del curl automático opcional no impide los informes de archivos locales ordinarios.

## Nombres de archivo y archivos recientes

Los nombres de archivos MRU se acortan solo cuando tienen más de 80 UTF-16 unidades de código. Una elipsis
intermedia preserva el principio, el final del nombre del archivo antes de su extensión y la extensión final
completa; Las rutas completas y los informes permanecen sin cambios. Los títulos de pestañas utilizan el mismo
algoritmo con un límite predeterminado configurable de 80.

Archivos recientes > Borrar borra inmediatamente tanto el menú MRU en vivo como sus rutas guardadas, dejando
intactas todas las pestañas abiertas. No aplica ni valida preferencias pendientes y no habilita Aplicar.
Cancelar o Escape conserva el historial borrado y descarta las ediciones pendientes. Borrar se desactiva
siempre que la lista está vacía y su estado se actualiza cuando nuevos informes completan la lista. Se informa
inmediatamente de un error de escritura en el registro. La aplicación de un nuevo límite de nombre de pestaña
actualiza cada pestaña abierta sin recargar su informe de medios.

## Licencia y redistribución

El espectador tiene la licencia MIT en license.txt.

MediaInfo es un componente de terceros. El único aviso de distribución mantenido es la raíz license.txt,
codificada como UTF-8 con CRLF e incluye el visor, las bibliotecas, los componentes incorporados
estáticamente, el icono y las tablas de traducción oficiales.

Este producto utiliza la biblioteca MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licencia: <https://mediaarea.net/en/MediaInfo/License>
- Windows descargas: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Dependencias

### Archivos

| Recurso | Arquitectura | Versión reportada por el componente | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Las rutas de la tabla son relativas al directorio del proyecto MediaInfo.

La biblioteca actual informa una versión en desarrollo; su fuente exacta commit no se puede recuperar de esa
cadena de versión. El aviso adjunto utiliza el texto de permiso y derechos de autor de 8.11.0, cuyos términos
de licencia también están presentes en la serie de desarrollo.

### Componentes incorporados

| Componente | Evidencia y alcance | Aviso |
| --- | --- | --- |
| MediaInfoLib | Versiones reales y exportaciones Unicode requeridas; binarios suministrados sin cambios | Copyright original específico de la versión, condiciones de redistribución y exención de responsabilidad |
| ZenLib | Referencias de proyectos estáticas e incrustadas ZenLib RTTI en los tres DLLs; revisiones exactas vinculadas no suministradas | Aviso zlib estilo ZenLib |
| zlib | Cadenas de versión inflate/deflate integradas: 1.3.2 en MediaInfo 26.10, 1.2.11 en 21.03, 1.2.7 en 0.7.60; curl reporta adicionalmente 1.3.1 y 1.2.8 | Avisos zlib originales para las cinco versiones |
| TinyXML-2 | Coincidencia de objetivos de origen modernos y binario RTTI; incluido en el proyecto heredado, pero no identificado de forma independiente en el binario heredado eliminado | Se conserva el aviso original estilo Lee Thomason zlib |
| Brian Gladman AES | Incluido en ambos destinos de biblioteca ascendentes modernos, con avisos de fuente permisivos coincidentes | 1998–2013 aviso de redistribución y exención de responsabilidad |
| Brian Gladman SHA-1/SHA-2 | Ambos objetivos modernos; Tablas de constantes SHA-256 y SHA-512 presentes en ambos binarios modernos | 1998–2010 aviso de redistribución y exención de responsabilidad |
| Brian Gladman HMAC | Ambos objetivos modernos y su código de lector curl/S3 | Aviso original de tres condiciones, incluido su párrafo de licencia alternativa |
| MD5 | Objetivos de origen modernos; La implementación de Colin Plumb establece explícitamente el dominio público | Atribución retenida |
| Base64 | Encabezado Markus Ewald en los tres árboles de origen correspondientes, acreditando Bob Withers | Se conserva la atribución de autoría original; calificación a continuación |
| fmt | 26.10 objetivo y fmt v11 format_error RTTI en binario | Aviso MIT original, incluida la excepción opcional |
| tfsxml | 26.10 origen destino | Aviso original MediaArea MIT |
| Interfaz Android JNI | JNI_OnLoad en realidad es exportado por el DLLs moderno; el encabezado JNI incluido es de AOSP | AOSP derechos de autor y licencia Apache completa 2.0 |
| libcurl | Binarios x86 suministrados; exportaciones de versiones reales; utilizado dinámicamente por el MediaInfo moderno | Avisos curl originales para 8.11.0 y 7.47.1 |
| Traducciones oficiales de los informes | Todas las fuentes 38 no modificadas CSV del directorio de idiomas MediaInfo v26.10; Las tablas 37 que no están en inglés están integradas, mientras que el inglés usa los valores predeterminados de DLL | El mismo proyecto BSD-2-Clause aviso retenido en el aviso combinado |
| Icono MediaInfo | Ícono oficial de múltiples imágenes sin modificar, revisión de fuente f057dd3649bc8692a83863b67770e22c9b9dd81a | Aviso y atribución originales BSD-2-Clause |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Los destinos de origen coincidentes establecen la inclusión en esas configuraciones de compilación
ascendentes; no prueban que todas las funciones sobrevivan a la optimización en los binarios del proveedor. No
se realiza ninguna reclamación de versión exacta para las dependencias cuya revisión no está registrada en
esos binarios.

### Componentes opcionales y bibliotecas del sistema

- Los proyectos de biblioteca Windows habilitan libcurl cargado en tiempo de ejecución para MediaInfo 26.10 y
  21.03. MediaInfo 0.7.60 fue construido con MEDIAINFO_LIBCURL_NO; su binario también contiene el diagnóstico
  de soporte para discapacitados. El espectador nunca descubre, extrae o carga curl para esa versión incluida.
- libmms está deshabilitado en los tres Windows DLLs suministrados, como lo confirman los mensajes integrados
  de soporte para discapacitados. No se redistribuye.
- Qt y wxWidgets pertenecen a compilaciones opcionales GUI. Ninguno de los dos está incluido en este visor ni
  en estas dependencias de DLL. Sus entradas genéricas se eliminaron de la licencia mostrada.
- Graphviz es un enlace de tiempo de ejecución opcional en el código ascendente moderno. No se redistribuye
  ningún Graphviz DLL.
- No se redistribuye ningún complemento FFmpeg.
- El MediaInfo DLLs importa directamente solo KERNEL32.dll. Esto no significa que su tiempo de ejecución
  vinculado estáticamente y su código auxiliar estén ausentes.
- El curl actual importa directamente WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll y KERNEL32.dll. XP
  curl importa directamente WS2_32.dll, WLDAP32.dll, ADVAPI32.dll y KERNEL32.dll. Estos son componentes
  Windows. Su disponibilidad la comprueba el cargador Windows.
- Curl informa Windows Schannel/WinSSL, no una compilación OpenSSL. Su dependencia de compresión adicional
  informada se incluye estáticamente zlib. No aparece ningún externo adicional que no sea Windows DLL en su
  tabla de importación directa.
- El visor en sí no tiene ninguna dependencia del tiempo de ejecución C/C++. El DLLs de terceros proporcionado
  contiene sus propias partes de tiempo de ejecución compiladas. Las compilaciones Windows utilizan
  herramientas de Microsoft; no hay evidencia que requiera las entradas de inventario genéricas libstdc++ o
  libc++.
- JPEG utiliza el sistema cargado dinámicamente GDI+. El empaquetador de recursos C# y PowerShell son
  herramientas de compilación y no son dependencias de tiempo de ejecución.

La inspección ordinaria de archivos locales no requiere un servidor MediaArea ni una base de datos en formato
descargada de forma remota. libcurl es utilizado por MediaInfo para entradas URL y referencias potencialmente
remotas en formatos de medios compatibles. Al agruparlo no se agrega un comando de apertura URL separado a
este visor.

### Almacenamiento de licencias y limitaciones

El único aviso de distribución mantenido es [license.txt](../license.txt) , codificado como UTF-8 con CRLF.
Las cláusulas de redistribución BSD, curl, zlib, MIT y Apache marcadas no requieren un archivo de aviso
separado físicamente al lado de cada DLL; el aviso combinado los acompaña en los materiales ejecutables y de
distribución.

El paquete MediaInfo 0.7.60 archivado utiliza su propia licencia específica de la versión e incluye el texto
antiguo GNU Library GPL. Sus términos distinguen expresamente la redistribución binaria no modificada de las
versiones modificadas; El enlace dinámico realizado por este visor no modifica el DLL proporcionado. Se
conservan sus condiciones originales y el texto de licencia adjunto. El espectador sigue teniendo la licencia
MIT.

Una atribución ascendente necesita calificación: el encabezado Markus Ewald Base64 no tiene permiso explícito
ni declaración de licencia. MediaArea describe la implementación de Bob Withers Base64 como dominio público en
su documentación relacionada MediaConch, pero eso no establece de forma independiente una concesión de
licencia para cada cambio de Ewald. No se ha inventado ninguna concesión de licencia para ese encabezado. Una
confirmación completa del proveedor de esa procedencia, las revisiones exactas de ZenLib y el desarrollo de
curl commit no estaban disponibles en los archivos binarios suministrados. Estos puntos impiden tratar este
inventario como un SBOM completo y certificado de forma independiente.

### Fuentes primarias

- [MediaInfo términos de redistribución](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 destino de biblioteca](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 destino de biblioteca](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 destino de biblioteca](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Tiempo de ejecución curl cargador](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Fuentes de ayuda incluidas y sus avisos](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib aviso](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib avisos de fuente](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 aviso](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 aviso](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licencia Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 descripción](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Las tablas del informe provienen de
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . El proyecto coincidente
LICENSE es <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
