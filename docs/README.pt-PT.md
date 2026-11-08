# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | **Português** | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | [Türkçe](README.tr-TR.md) | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

Visualizador nativo para Windows x86 de relatórios MediaInfo.dll. Cada ficheiro tem um separador só de
leitura.

[Compilação e compatibilidade](#compilação) | [Auditoria de dependências](#dependências) | [Licença](../license.txt)

## Compilação

Abra MediaInfo.sln em Visual Studio 2015 com o conjunto de ferramentas Visual C++ v140 instalado. Escolha Release | Win32 e construa a solução. A única plataforma de aplicação é a Win32 (x86).

[PCRE2 10.49](https://github.com/PCRE2Project/pcre2/tree/pcre2-10.49) — UTF-16, ligação estática,
BSD-3-Clause. [license.txt](../license.txt). [Código-fonte](../MediaInfo/PCRE2/).
A PCRE2 está integrada no executável e não requer uma DLL separada nem uma instalação adicional.

Saídas:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

O visualizador não liga o tempo de execução C ou C++ e não necessita de um redistribuível MSVC. O
MediaInfo.dll selecionado pode ter as suas próprias dependências.

A construção requer Windows PowerShell e .NET Framework. Estes são apenas requisitos de construção; o
executável nativo não requer PowerShell nem .NET.

### Pacote de distribuição

Após construir Release, execute `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1`
. O script cria `MediaInfo-<version>-win32.zip` no diretório da solução, utilizando a versão do ficheiro
executável em quatro partes. O ficheiro contém `MediaInfo.exe` e o `license.txt` combinado diretamente na sua
raiz.

## Compatibilidade

O visualizador Win32 foi concebido para utilizar Windows NT 4.0 APIs.

O executável inclui três bibliotecas x86 MediaInfo: 26.10 para o Windows atual, 21.03 do pacote Windows XP e
0.7.60 do pacote Windows 95–2000. A arquitetura de uma biblioteca por si só não determina a compatibilidade do
sistema operativo. O visualizador testa as bibliotecas agrupadas da mais recente para a mais antiga e pára
após o primeiro carregamento e consulta de versão bem-sucedidos.

Windows 95 não é atualmente um tempo de execução compatível.

## Utilização

- Ficheiro > Abrir (Ctrl+O) abre a caixa de diálogo do ficheiro Windows com seleção múltipla. Em Windows Vista
  e posteriores, Abrir e Guardar utilizam a moderna caixa de diálogo de item comum; Windows mais antigos
  utilizam os diálogos comuns herdados.
- Arraste um ou mais ficheiros para a janela, para o ícone do EXE ou para o respetivo atalho, ou indique os
  caminhos na linha de comandos. Se não forem permitidas várias instâncias, os ficheiros abrem-se na janela
  que já está em execução.
- Cada caminho completo normalizado distinto possui um separador. Reabrir um ficheiro já aberto seleciona o
  seu separador existente sem recarregar ou alterar o seu relatório, seleção ou posição de rolagem. As
  comparações ignoram as maiúsculas e minúsculas. As aberturas de vários ficheiros processam a lista por ordem
  e deixam ativo o último ficheiro processado com sucesso, quer seja recém-aberto ou já aberto. Passar o rato
  sobre o cabeçalho de um separador apresenta o caminho completo do ficheiro numa dica de ferramenta nativa,
  incluindo quando o nome do ficheiro apresentado é abreviado.
- O menu Ficheiro lista os oito ficheiros carregados mais recentemente diretamente acima de Sair, entre
  separadores. As entradas mostram apenas um número e um nome de ficheiro. Selecionar uma entrada abre o seu
  caminho completo armazenado ou seleciona o seu separador existente; a reabertura bem-sucedida move-o para o
  topo sem duplicados. Selecionar um ficheiro indisponível pergunta se a sua entrada de ficheiros recentes
  deve ser removida. O ícone de pergunta nativo e os botões Yes/No são utilizados. Sim é o padrão e remove a
  entrada do menu e do registo; Não o retém. O prompt inclui o caminho completo.
- A roda do rato sobre os cabeçalhos das guias transbordantes faz rolar a faixa de cabeçalho uma guia por
  mensagem sem alterar a seleção ou o foco.
- Ctrl+Tab e Ctrl+Shift+Tab alternam guias; Ctrl+W fecha a aba ativa. Clicar com o botão do meio no cabeçalho
  de um separador fecha esse separador, preservando qualquer outro separador ativo. Ficheiro > Fechar tudo
  fecha todas as guias, incluindo os relatórios em fila. Arquivo > Sair (Alt+F4) fecha o aplicativo.
- O menu de contexto do cabeçalho de um separador inclui Fechar separador. Ative Fechar separadores com
  duplo clique nas Preferências para fechar um separador com um duplo clique no cabeçalho. A opção está
  desativada por predefinição e é guardada.
- Um duplo clique no texto do relatório seleciona uma palavra. Um triplo clique seleciona uma linha
  lógica. Arrastar expande a seleção por palavras ou linhas.
- Ctrl+A seleciona o relatório; Ctrl+C cópia.
- Editar > Localizar (Ctrl+F) pesquisa no separador de relatório ativo ou na área de texto de Ajuda ou
  Acerca de, conforme a janela que tem o foco. A janela de pesquisa mantém a última origem selecionada
  enquanto tem o foco. F3 repete a pesquisa; Shift+F3 inverte a direção. Ao atingir uma extremidade do
  texto, a pesquisa continua na outra. Opções > Moldar texto afeta apenas o separador ativo; a marca
  acompanha o separador selecionado. A janela de pesquisa pode ser minimizada e redimensionada
  horizontalmente; a posição e a opção Sempre em cima são memorizadas. São guardadas até 30 pesquisas e
  as respetivas opções apenas até a aplicação ser encerrada. As opções de início e fim referem-se às
  linhas lógicas. As expressões regulares utilizam a sintaxe PCRE2. Os restantes comandos do menu Editar
  aplicam-se ao separador de relatório ativo. Enter inicia a pesquisa; Shift+Enter inverte a direção
  escolhida. «Distinguir maiúsculas de minúsculas» distingue maiúsculas de minúsculas; «Procurar para
  trás» pesquisa em direção ao início do texto. A escolha de uma entrada do histórico repõe as cinco
  opções de pesquisa, incluindo o estado do modo de expressão regular; «Sempre em cima» é independente.
  «Expressão regular» desativa «A linha começa por» e «A linha termina com». Com ambas as opções de
  início e fim de linha ativas, basta uma correspondência numa das extremidades. «Moldar texto» altera
  apenas a apresentação.
- Opções > Preferências (Ctrl+G) abre um único diálogo de preferências para os caminhos MediaInfo e curl,
  fonte de relatório, suavização de fonte, idioma de interface e idioma de relatório. Um caminho DLL vazio
  permite a descoberta automática.
- O botão de tipo de letra apresenta a família, o tamanho do ponto e o estilo e abre a caixa de diálogo de
  tipo de letra padrão Windows. O predefinido restaura Consolas ou Courier New se Consolas não estiver
  disponível; o botão Padrão fica desativado enquanto o padrão está selecionado. As fontes selecionadas pelo
  utilizador são mantidas sem substituição pelo código da aplicação.
- As opções de antialiasing de fonte são ClearType quando suportadas, GDI e None. A escolha inicial é
  ClearType quando suportado, caso contrário GDI. As definições de tipo de letra afetam os separadores
  de relatórios, as respetivas exportações para imagem e a impressão de relatórios. Ajuda e Acerca de
  mantêm os seus próprios tipos de letra.
- A Ajuda abre uma janela separada sem janela restrita com a sua própria entrada na barra de tarefas e botão
  de minimizar. Sobre é uma caixa de diálogo modal; o cabeçalho do produto lista todas as três versões DLL
  incorporadas.

Ficheiro > Configurar página… abre as definições de papel, orientação e margens para a sessão atual.
Imprimir… (Ctrl+P) abre a caixa de diálogo de impressão do sistema; o Windows 11 fornece uma
pré-visualização, enquanto o Windows 10 e anteriores mantêm a caixa de diálogo clássica. Ctrl+P imprime
o separador ativo da janela principal ou a área de texto de Ajuda ou Acerca de, conforme a janela que
tem o foco. Os relatórios usam o tipo de letra escolhido, a Ajuda o tipo de letra dos diálogos do
sistema e Acerca de o da sua área de texto. Se não houver separadores abertos mas a Ajuda estiver
aberta, Configurar página… e Imprimir… continuam disponíveis; Imprimir… imprime a Ajuda. A Ajuda usa a
caixa de diálogo de impressão da janela principal; premir Ctrl+P novamente na Ajuda volta a colocar a
mesma caixa de diálogo em primeiro plano. As linhas longas são ajustadas e o texto é dividido em
páginas. A impressão decorre em segundo plano.

Abrir pasta… abre os ficheiros contidos diretamente na pasta selecionada, cada um no seu próprio separador. As
subpastas não são incluídas. Abrir e Abrir pasta partilham a última pasta selecionada. A exportação memoriza a
sua própria pasta, Documentos por predefinição.

O modo avançado apresenta campos adicionais no relatório.

Análise completa examina o ficheiro inteiro e pode demorar mais tempo. Estas opções de relatório e Nível de
rastreio pertencem a cada separador; uma alteração atualiza apenas o separador ativo. A última combinação
escolhida manualmente é guardada para novos separadores e para a próxima execução. Um relatório armazenado em
cache correspondente é reutilizado enquanto o ficheiro permanece inalterado.

Formatos conhecidos, Codecs conhecidos e Parâmetros conhecidos abrem nos seus próprios separadores de
relatório.

O tamanho e a localização da janela inicial são selecionados por Windows. O posicionamento da janela guardado
anteriormente substitui estes padrões em inicializações posteriores.

O lado esquerdo da barra de estado apresenta os caminhos dos ficheiros e o progresso do carregamento; o lado
direito apresenta a versão da MediaInfo.dll carregada. Os caminhos longos são abreviados com reticências de
acordo com o espaço disponível.

## Criar ficheiro de cabeçalho

O menu Ferramentas é o quarto na barra de menus. O seu comando Criar ficheiro de cabeçalho… abre um ficheiro
de origem independentemente dos separadores do relatório e copia os seus primeiros 524288 bytes (512 KiB). Um
ficheiro mais curto é copiado por completo; um ficheiro vazio produz uma saída vazia. Esta é uma leitura comum
de ficheiro binário, sem análise MediaInfo nem necessidade de MediaInfo.dll. A ferramenta deixa inalteradas os
separadores do relatório e a lista de ficheiros recentes do visualizador.

Após a leitura, a caixa de diálogo Guardar como inicia-se na pasta do ficheiro de origem e sugere
video.mp4.header para video.mp4: .header é anexado ao nome original completo. Pode alterar o nome e a pasta de
destino. Cancelar qualquer caixa de diálogo não grava qualquer saída. A substituição de um destino existente
requer confirmação. O ficheiro de origem permanece inalterada; uma falha ao guardar preserva o destino
anterior. Para abrir e guardar são utilizadas as caixas de diálogo do sistema mais modernas disponíveis nessa
versão do Windows.

Na inicialização da aplicação, a ferramenta obtém a sua pasta de entrada inicial de Ficheiro > Abrir. Se não
tiver sido guardada nenhuma pasta, o Windows escolhe o local inicial. Depois de um ficheiro de entrada ser
selecionado, a ferramenta recorda a sua própria pasta apenas até a aplicação sair, mesmo que o Guardar como
seja cancelado. Não altera as pastas utilizadas por Abrir e Exportar nem guarda a sua própria pasta nas
definições da aplicação. Cada caixa de diálogo Guardar como inicia-se na pasta do ficheiro de entrada
atualmente selecionado, independentemente do destino de gravação anterior.

## Pesquisa de bibliotecas

Um caminho manual salvo é tentado primeiro. Se não puder ser carregado, a descoberta automática tentará:

1. MediaInfo.dll ao lado do executável e, em seguida, em cada diretório pai até que a unidade ou UNC partilhem
   a raiz.
2. ProgramFiles, ProgramFiles(x86) e ProgramW6432.
3. LOCALAPPDATA e APPDATA.

Sob estas raízes de instalação, a descoberta verifica MediaInfo, MediaArea\MediaInfo, MediaArea,
MediaArea.net\MediaInfo, Programs\MediaInfo, Programs\MediaArea\MediaInfo. Os locais ilegíveis e DLLs
incompatíveis são ignorados. Não verifica recursivamente o disco.

Se não for encontrado nenhum DLL externo compatível, o visualizador tenta as versões incorporadas por esta
ordem: 26.10, 21.03, 0.7.60. Extrai e testa uma versão de cada vez. Depois de uma versão ser carregada com
êxito, as versões mais antigas não são extraídas nem testadas. Distribuir MediaInfo.exe por si só é
suficiente; um DLL externo compatível tem sempre prioridade e pode ser atualizado de forma independente.

Uma alteração manual da biblioteca com falha mantém a biblioteca que já foi carregada.

## Exportação de relatório

Os formatos Guardar como estão ordenados TXT, BMP, GIF, JPEG, PNG, TIFF e WebP. Os codificadores não
suportados são omitidos nas caixas de diálogo modernas e legadas.

TXT oferece ANSI, UTF-8, UTF-8 com BOM, UTF-16 BE com BOM e UTF-16 LE com BOM. A segunda opção, UTF-8 sem BOM,
é a predefinida. O texto completo do relatório e as quebras de linha originais são preservados.

BMP, PNG e TIFF preservam todas as cores renderizadas; GIF89a preserva a paleta renderizada exata quando a
imagem tem no máximo 256 cores. Exportar grava sempre o formato selecionado ou reporta um erro; nunca
substitui outro formato.

## Idiomas de interface e de relatório

As preferências (Opções > Preferências, Ctrl+G) contêm caminhos das bibliotecas, tipo de letra do relatório,
suavização e idiomas. A interface tem 36 variantes e segue inicialmente o Windows. Os relatórios usam sempre o
inglês original da biblioteca, independentemente do Windows e da interface. Só uma escolha manual muda o
idioma: inglês, 37 traduções ou uma tabela CSV MediaInfo personalizada.

OK ou Aplicar confirma as alterações; Cancelar descarta as pendentes. As preferências permitem limitar os
nomes dos separadores (80 por predefinição) e limpar a lista dos ficheiros recentes. Os nomes longos mantêm
início, fim e extensão com reticências no meio.

Por predefinição, só é permitida uma instância e os arranques seguintes enviam os ficheiros para a janela
aberta. Nas preferências, é possível permitir várias instâncias. Com várias janelas, apenas a primeira de cada
formulário recupera a posição guardada; as seguintes recuperam apenas o tamanho.

Alterar apenas a interface deixa o texto dos relatórios abertos inalterado. Uma alteração no idioma do
relatório aplicada manualmente recarrega os seus relatórios, preservando a ordem de tabulação e a ordem MRU.

## libcurl

A descoberta automática de curl verifica ao lado do MediaInfo DLL selecionado e, em seguida, do
executable/ancestor partilhado, dos ficheiros de programas e dos locais de instalação do utilizador. Se não
for encontrado nenhum curl externo compatível, a versão atual incorporada ou XP correspondente será extraída
para a cache verificada por utilizador. O MediaInfo 0.7.60 mais antigo ignora totalmente a descoberta,
extração e carregamento do curl. Um curl inválido explicitamente selecionado rejeita a alteração de
preferência; a falta do curl automático opcional não impede os relatórios comuns de ficheiros locais.

## Nomes dos ficheiros e ficheiros recentes

Os nomes de ficheiros MRU são abreviados apenas quando são superiores a unidades de código 80 UTF-16. As
reticências do meio preservam o início, o fim do nome do ficheiro antes da sua extensão e a extensão final
completa; caminhos completos e relatórios permanecem inalterados. As legendas dos separadores utilizam o mesmo
algoritmo com um limite padrão configurável de 80.

Ficheiros recentes > Limpar limpa imediatamente o menu MRU ativo e os seus caminhos guardados, deixando todas
as abas abertas intactas. Não aplica nem valida preferências pendentes e não ativa Aplicar. Cancelar ou Escape
preserva o histórico limpo enquanto descarta as edições pendentes. Limpar é desativado sempre que a lista está
vazia e o seu estado é atualizado quando novos relatórios preenchem a lista. Uma falha na gravação do registo
é reportada imediatamente. A aplicação de um novo limite de nome de separador atualiza cada separador aberto
sem recarregar o seu relatório de media.

## Licença e redistribuição

O visualizador está licenciado sob a licença MIT em license.txt.

MediaInfo é um componente de terceiros. O único aviso de distribuição mantido é root license.txt, codificado
como UTF-8 com CRLF e incluindo o visualizador, bibliotecas, componentes incorporados estaticamente, ícones e
tabelas oficiais de tradução.

Este produto utiliza a biblioteca MediaInfo, Copyright (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Licença: <https://mediaarea.net/en/MediaInfo/License>
- Windows downloads: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Dependências

### Ficheiros

| Recurso | Arquitetura | Versão informada pelo componente | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Os caminhos da tabela são relativos ao diretório do projeto MediaInfo.

A biblioteca atual reporta uma versão em desenvolvimento; a sua origem exata commit não pode ser recuperada a
partir desta string de versão. O aviso que o acompanha utiliza o texto de permissão e direitos de autor 8.11.0
upstream, cujos termos de licença também estão presentes na série de desenvolvimento.

### Componentes incorporados

| Componente | Evidência e âmbito | Aviso |
| --- | --- | --- |
| MediaInfoLib | Versões reais e exportações Unicode necessárias; binários fornecidos inalterados | Direitos de autor originais específicos da versão, condições de redistribuição e isenção de responsabilidade |
| ZenLib | Referências estáticas de projetos e ZenLib RTTI incorporados em todos os três DLLs; revisões ligadas exatas não fornecidas | Aviso ZenLib estilo zlib |
| zlib | Strings de versão inflate/deflate incorporadas: 1.3.2 em MediaInfo 26.10, 1.2.11 em 21.03, 1.2.7 em 0.7.60; curl reporta adicionalmente 1.3.1 e 1.2.8 | Avisos zlib originais para todas as cinco versões |
| TinyXML-2 | Correspondência de destinos de origem modernos e RTTI binário; incluído no projeto legado, mas não identificado de forma independente no binário legado removido | Aviso original estilo Lee Thomason zlib retido |
| Brian Gladman AES | Incluído em ambos os destinos modernos da biblioteca upstream, com avisos de origem permissivos correspondentes | 1998–2013 aviso de redistribuição e isenção de responsabilidade |
| Brian Gladman SHA-1/SHA-2 | Ambos alvos modernos; Tabelas constantes SHA-256 e SHA-512 presentes em ambos os binários modernos | 1998–2010 aviso de redistribuição e isenção de responsabilidade |
| Brian Gladman HMAC | Ambos os alvos modernos e o seu código de leitor curl/S3 | Aviso original de três condições, incluindo o seu parágrafo de licença alternativa |
| MD5 | Destinos de origem modernos; A implementação de Colin Plumb declara explicitamente o domínio público | Atribuição retida |
| Base64 | Markus Ewald cabeçalho em todas as três árvores de origem correspondentes, creditando Bob Withers | Atribuição de autoria originária mantida; qualificação abaixo |
| fmt | 26.10 alvo e fmt v11 format_error RTTI no binário | Aviso MIT original, incluindo exceção opcional |
| tfsxml | 26.10 destino de origem | Aviso MediaArea MIT original |
| Interface Android JNI | JNI_OnLoad é realmente exportado pelo DLLs moderno; o cabeçalho JNI incluído é de AOSP | AOSP direitos de autor e licença Apache completa 2.0 |
| libcurl | Binários x86 fornecidos; exportações de versões reais; utilizado dinamicamente pelo MediaInfo moderno | Avisos curl originais para 8.11.0 e 7.47.1 |
| Traduções oficiais dos relatórios | Todas as fontes CSV não modificadas de 38 do diretório de idiomas MediaInfo v26.10; As tabelas 37 que não estão em inglês são incorporadas, enquanto o inglês utiliza as normas DLL | Mesmo aviso de projeto BSD-2-Clause retido no aviso combinado |
| ícone MediaInfo | Ícone oficial de múltiplas imagens não modificado, revisão de origem f057dd3649bc8692a83863b67770e22c9b9dd81a | Aviso e atribuição BSD-2-Clause original |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Os destinos de origem correspondentes estabelecem a inclusão nestas definições de compilação upstream; não
provam que todas as funções sobrevivem à otimização nos binários do fornecedor. Nenhuma reivindicação de
versão exata é feita para dependências cuja revisão não está registada nestes binários.

### Componentes opcionais e bibliotecas de sistema

- Os projetos da biblioteca Windows permitem libcurl carregado em tempo de execução para MediaInfo 26.10 e
  21.03. MediaInfo 0.7.60 foi construído com MEDIAINFO_LIBCURL_NO; o seu binário também contém o diagnóstico
  de suporte desativado. O visualizador nunca descobre, extrai ou carrega curl para essa versão empacotada.
- libmms está desativado em todos os três Windows DLLs fornecidos, conforme confirmado pelas suas mensagens
  incorporadas de suporte desativado. Não é redistribuído.
- Qt e wxWidgets pertencem a compilações opcionais de GUI. Nenhum deles está incluído neste visualizador ou
  nestas dependências DLL. As suas entradas genéricas foram removidas da licença apresentada.
- Graphviz é um gancho de tempo de execução opcional no código upstream moderno. Nenhum Graphviz DLL é
  redistribuído.
- Nenhum plugin FFmpeg é redistribuído.
- O MediaInfo DLLs importa diretamente apenas KERNEL32.dll. Isto não significa que o tempo de execução e o
  código auxiliar ligados estaticamente estejam em falta.
- O curl atual importa diretamente WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll e KERNEL32.dll. XP curl
  importa diretamente WS2_32.dll, WLDAP32.dll, ADVAPI32.dll e KERNEL32.dll. Estes são componentes Windows. A
  sua disponibilidade é verificada pelo carregador Windows.
- Curl reporta Windows Schannel/WinSSL, e não uma compilação OpenSSL. A sua dependência de compressão
  adicional reportada está incluída estaticamente zlib. Nenhum DLL externo não-Windows adicional aparece na
  sua tabela de importação direta.
- O visualizador em si não tem dependência de tempo de execução C/C++. O DLLs de terceiros fornecido contém as
  suas próprias partes de tempo de execução compiladas. As compilações Windows utilizam ferramentas da
  Microsoft; não há provas que exijam entradas de inventário genéricas libstdc++ ou libc++.
- JPEG utiliza sistema carregado dinamicamente GDI+. O empacotador de recursos C# e PowerShell são ferramentas
  de construção e não são dependências de tempo de execução.

A inspeção comum de ficheiros locais não requer um servidor MediaArea ou uma base de dados em formato
descarregado remotamente. O libcurl é utilizado pelo MediaInfo para entradas URL e referências potencialmente
remotas nos formatos de media suportados. Agregá-lo não adiciona um comando de abertura URL separado a este
visualizador.

### Armazenamento de licenças e limitações

O único aviso de distribuição mantido é [license.txt](../license.txt) , codificado como UTF-8 com CRLF. As
cláusulas de redistribuição BSD, curl, zlib, MIT e Apache verificadas não requerem um ficheiro de aviso
separado fisicamente ao lado de cada DLL; o aviso combinado acompanha-os nos materiais executáveis e de
distribuição.

O pacote MediaInfo 0.7.60 arquivado utiliza a sua própria licença específica de versão e inclui o texto antigo
GNU Library GPL. Os seus termos distinguem expressamente a redistribuição binária não modificada das versões
modificadas; a ligação dinâmica por este visualizador não modifica o DLL fornecido. As suas condições
originais e o texto da licença que o acompanha são mantidos. O visualizador permanece licenciado pelo MIT.

Uma atribuição upstream necessita de qualificação: o cabeçalho Markus Ewald Base64 não tem permissão explícita
ou declaração de licença. MediaArea descreve a implementação de Bob Withers Base64 como domínio público na sua
documentação MediaConch relacionada, mas isto não estabelece de forma independente uma concessão de licença
para cada alteração de Ewald. Nenhuma concessão de licença foi inventada para este cabeçalho. Uma confirmação
completa do fornecedor desta origem, as revisões exatas do ZenLib e o desenvolvimento do curl commit não
estavam disponíveis nos binários fornecidos. Estes pontos evitam tratar este inventário como um SBOM completo
e certificado de forma independente.

### Fontes primárias

- [MediaInfo termos de redistribuição](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 alvo da biblioteca](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 alvo da biblioteca](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 alvo da biblioteca](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Carregador curl de tempo de execução](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Fontes auxiliares agrupadas e seus avisos](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib aviso](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib avisos de origem](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 aviso](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 aviso](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Licença Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 descrição](https://github.com/MediaArea/MediaConch/blob/master/README.md)

As tabelas de relatórios provêm de
<https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language> . O projeto
correspondente LICENSE é <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> .

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
