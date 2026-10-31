# MediaInfo Viewer

[Čeština](README.cs-CZ.md) | [English (US)](../README.md) | [English (UK)](README.en-GB.md) | [English (Australia)](README.en-AU.md) | [Deutsch](README.de-DE.md) | [Français](README.fr-FR.md) | [Español](README.es-ES.md) | [Italiano](README.it-IT.md) | [Português](README.pt-PT.md) | [Polski](README.pl-PL.md) | [Slovenčina](README.sk-SK.md) | [Dansk](README.da-DK.md) | [Suomi](README.fi-FI.md) | [Íslenska](README.is-IS.md) | [Norsk (bokmål)](README.nb-NO.md) | [Svenska](README.sv-SE.md) | **Türkçe** | [Eesti](README.et-EE.md) | [Gaeilge](README.ga-IE.md) | [Lietuvių](README.lt-LT.md) | [Latviešu](README.lv-LV.md) | [Magyar](README.hu-HU.md) | [Malti](README.mt-MT.md) | [Nederlands](README.nl-NL.md) | [Română](README.ro-RO.md) | [Ελληνικά](README.el-GR.md) | [Bosanski](README.bs-Latn-BA.md) | [Hrvatski](README.hr-HR.md) | [Slovenščina](README.sl-SI.md) | [Crnogorski](README.cnr-Latn-ME.md) | [Беларуская](README.be-BY.md) | [Български](README.bg-BG.md) | [Македонски](README.mk-MK.md) | [Српски](README.sr-Cyrl-RS.md) | [Українська](README.uk-UA.md) | [Русский](README.ru-RU.md)

MediaInfo.dll raporları için yerel Windows x86 görüntüleyicisi. Her dosyanın salt okunur bir sekmesi vardır.

[Derleme ve uyumluluk](#uygulamayı-oluşturma) | [Bağımlılık denetimi](#bağımlılıklar) | [Lisans](../license.txt)

## Uygulamayı oluşturma

MediaInfo.sln dosyasını Visual Studio 2015 içinde Visual C++ v140 yüklü araç seti ile açın. Release'yi seçin | Win32 ve çözümü oluşturun. Tek uygulama platformu Win32 (x86)'dir.

Çıkışlar:

- Release\MediaInfo.exe
- Debug\MediaInfo.exe

Görüntüleyici, C veya C++ çalışma zamanını bağlamaz ve MSVC yeniden dağıtılabilir öğeye ihtiyaç duymaz.
Seçilen MediaInfo.dll kendi bağımlılıklarına sahip olabilir.

Bina Windows PowerShell ve .NET Framework gerektirir. Bunlar yalnızca derleme gereksinimleridir; yerel
yürütülebilir dosya ne PowerShell ne de .NET gerektirir.

### Release paketi

Release derlendikten sonra `powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\PackageRelease.ps1`
komutunu çalıştırın. Betik, yürütülebilir dosyanın dört parçalı dosya sürümünü kullanarak çözüm dizininde
`MediaInfo-<version>-win32.zip` oluşturur. Arşiv `MediaInfo.exe` ve birleştirilmiş `license.txt` 'yi doğrudan
kökünde içerir.

## Uyumluluk

Win32 görüntüleyici Windows NT 4.0 APIs kullanacak şekilde tasarlanmıştır.

Yürütülebilir dosya üç x86 MediaInfo kitaplığı içerir: geçerli Windows için 26.10, Windows XP paketinden 21.03
ve Windows 95–2000 paketinden 0.7.60. Bir kütüphanenin mimarisi tek başına işletim sistemi uyumluluğunu
belirlemez. Görüntüleyici, paketlenmiş kitaplıkları en yeniden en eskiye doğru dener ve ilk başarılı yükleme
ve sürüm sorgusundan sonra durur.

Windows 95 şu anda desteklenen bir çalışma zamanı değil.

## Uygulamayı kullanma

- Dosya > Aç (Ctrl+O), çoklu seçimle Windows dosya iletişim kutusunu açar. Windows Vista ve sonrasında, Aç ve
  Kaydet, modern Ortak Öğe İletişim Kutusunu kullanır; eski Windows eski ortak diyalogları kullanır.
- Bir veya daha fazla dosyayı pencereye, EXE simgesine veya kısayoluna sürükleyin ya da yollarını komut
  satırında belirtin. Birden çok örneğe izin verilmiyorsa dosyalar zaten açık olan pencerede açılır.
- Her farklı normalleştirilmiş tam yolun bir sekmesi vardır. Zaten açık olan bir dosyayı yeniden açmak,
  raporunu, seçimini veya kaydırma konumunu yeniden yüklemeden veya değiştirmeden mevcut sekmeyi seçer.
  Karşılaştırmalarda yol harfi büyük/küçük harf dikkate alınmaz. Çoklu dosya açılışlarında liste sırayla
  işlenir ve ister yeni açılmış olsun, ister zaten açık olsun, başarıyla işlenen son dosyayı aktif bırakır.
  Bir sekme başlığının üzerine gelindiğinde, görüntülenen dosya adının kısaltıldığı durumlar da dahil olmak
  üzere, yerel araç ipucunda tam dosya yolu görüntülenir.
- Dosya menüsü, en son yüklenen sekiz dosyayı, ayırıcılar arasında, Çıkış'ın hemen üzerinde listeler.
  Girişlerde yalnızca sayı ve dosya adı gösterilir. Bir giriş seçildiğinde, kayıtlı tam yolu açılır veya
  mevcut sekmesi seçilir; başarılı bir şekilde yeniden açma, onu kopyalar olmadan en üste taşır.
  Kullanılamayan bir dosyanın seçilmesi, bu dosyanın son dosyalar girişinin kaldırılıp kaldırılmayacağını
  sorar. Yerel soru simgesi ve Yes/No düğmeleri kullanılır. Evet varsayılandır ve girişi menüden ve kayıt
  defterinden kaldırır; Hayır onu korur. Bilgi istemi tam yolu içerir.
- Taşan sekme başlıklarının üzerindeki fare tekerleği, seçimi veya odağı değiştirmeden başlık şeridini mesaj
  başına bir sekme kaydırır.
- Ctrl+Tab ve Ctrl+Shift+Tab sekmeleri değiştirir; Ctrl+W etkin sekmeyi kapatır. Bir sekme başlığına orta
  tıklama, diğer etkin sekmeleri korurken o sekmeyi kapatır. Dosya > Tümünü Kapat, sıraya alınmış raporlar da
  dahil olmak üzere tüm sekmeleri kapatır. Dosya > Çıkış (Alt+F4) uygulamayı kapatır.
- Çift tıklama bir kelimeyi seçer. Üç tıklama mantıksal bir çizgi seçer. Sürükleme, seçimi kelimelere veya
  satırlara göre genişletir.
- Ctrl+A raporu seçer; Ctrl+C kopyalar.
- Ayarlar > Tercihler (Ctrl+G), MediaInfo ve curl yolları, rapor yazı tipi, yazı tipi kenar yumuşatma, arayüz
  dili ve rapor dili için tek bir tercihler iletişim kutusu açar. Boş bir DLL yolu otomatik keşif sağlar.
- Yazı tipi düğmesi aileyi, punto boyutunu ve stilini görüntüler ve standart Windows yazı tipi iletişim
  kutusunu açar. Varsayılan, Consolas'yi veya Consolas kullanılamıyorsa Courier New'yi geri yükler; Varsayılan
  seçiliyken Varsayılan düğmesi devre dışı bırakılır. Kullanıcı tarafından seçilen yazı tipleri, uygulama
  koduyla değiştirilmeden korunur.
- Yazı tipi kenar yumuşatma seçenekleri desteklendiğinde ClearType, GDI ve Hiçbiri'dir. Desteklendiğinde ilk
  seçim ClearType, aksi takdirde GDI'dir. Yazı tipi ayarları yalnızca medya raporlarını ve bunların görüntü
  aktarımlarını etkiler.
- Dosya > Dışa Aktar (Ctrl+E), Windows Farklı Kaydet iletişim kutusunu açar ve görünür alanın dışındaki metin
  de dahil olmak üzere etkin raporun tamamını TXT, BMP, GIF, JPEG, PNG, TIFF veya WebP'ye aktarır.
- Yardım, kendi görev çubuğu girişi ve simge durumuna küçültme düğmesiyle ayrı bir modelsiz pencere açar.
  Hakkında kalıcı bir iletişim kutusudur; ürün başlığı, üç yerleşik DLL sürümünün tümünü listeler.

Yazdır… (Ctrl+P) sistemin yazıcı seçme iletişim kutusunu açar ve etkin sekmenin tamamını önizleme olmadan
yazdırır. Seçilen rapor yazı tipi kullanılır; uzun satırlar kaydırılır ve metin sayfalara bölünür. Yazdırma
arka planda çalışır.

Klasör aç… seçili klasörün doğrudan içindeki dosyaları, her biri kendi sekmesinde olacak şekilde açar. Alt
klasörler dahil edilmez. Aç ve Klasör aç, son seçilen klasörü paylaşır. Dışa aktarma kendi klasörünü hatırlar;
varsayılan klasör Belgeler’dir.

Gelişmiş mod, raporda ek alanlar gösterir.

Tam Ayrıştırma dosyanın tamamını inceler ve daha uzun sürebilir. Bu rapor seçenekleri ve İzleme Düzeyi her
sekmeye aittir; bir değişiklik yalnızca etkin sekmeyi yeniler. Manuel olarak seçilen son kombinasyon, yeni
sekmeler ve bir sonraki başlatma için kaydedilir. Eşleşen önbelleğe alınmış bir rapor, dosya değişmeden
kaldığı sürece yeniden kullanılır.

Bilinen biçimler, Bilinen kodekler ve Bilinen parametreler kendi rapor sekmelerinde açılır.

Başlangıç pencere boyutu ve konumu Windows tarafından seçilir. Daha önce kaydedilen pencere yerleşimi, daha
sonraki başlatmalarda bu varsayılan ayarları geçersiz kılar.

Durum çubuğunun sol tarafı dosya yollarını ve yükleme ilerlemesini, sağ tarafı ise yüklenen MediaInfo.dll
sürümünü gösterir. Uzun yollar kullanılabilir alana göre üç noktayla kısaltılır.

## Üst bilgi dosyası oluştur

Araçlar menüsü, menü çubuğundaki üçüncü menüdür. Üst bilgi dosyası oluştur… komutu, rapor sekmelerinden
bağımsız olarak bir kaynak dosyayı açar ve ilk 524288 baytını (512 KiB) kopyalar. Daha kısa bir dosya tam
olarak kopyalanır; boş bir dosya boş bir çıktı üretir. Bu, MediaInfo analizi veya MediaInfo.dll gereksinimi
olmadan sıradan bir ikili dosya okumasıdır. Araç, rapor sekmelerini ve görüntüleyicinin son dosyalar listesini
değiştirmeden bırakır.

Okuduktan sonra, kaynak dosyanın klasöründe Farklı Kaydet iletişim kutusu başlar ve video.mp4 için
video.mp4.header'ı önerir: .header orijinal adın tamamına eklenir. Hem adı hem de hedef klasörü
değiştirebilirsiniz. Her iki iletişim kutusunun iptal edilmesi hiçbir çıktı yazmaz. Mevcut bir hedefi
değiştirmek onay gerektirir. Kaynak değişmeden kalır; başarısız bir kaydetme önceki hedefi korur. Açma ve
kaydetme işlemlerinde kullanılan Windows sürümünde mevcut olan en yeni sistem iletişim kutuları kullanılır.

Uygulama başlatıldığında araç, ilk giriş klasörünü Dosya > Aç konumundan alır. Hiçbir klasör kaydedilmemişse
Windows başlangıç konumunu seçer. Bir giriş dosyası seçildikten sonra araç, Farklı Kaydet iptal edilse bile
yalnızca uygulamadan çıkana kadar kendi klasörünü hatırlar. Aç ve Dışa aktar tarafından kullanılan klasörleri
değiştirmez ve kendi klasörünü uygulama ayarlarına kaydetmez. Her Farklı Kaydet iletişim kutusu, önceki
kaydetme hedefine bakılmaksızın, o anda seçili olan giriş dosyasının klasöründe başlar.

## Kitaplık arama

Önce kayıtlı bir manuel yol denenir. Yüklenemiyorsa otomatik bulma şunu dener:

1. MediaInfo.dll yürütülebilir dosyanın yanında, ardından sürücüye kadar her ana dizinde veya UNC paylaşım
   kökünde.
2. ProgramFiles, ProgramFiles(x86) ve ProgramW6432.
3. LOCALAPPDATA ve APPDATA.

Bu kurulum kökleri altında, keşif MediaInfo, MediaArea\MediaInfo, MediaArea, MediaArea.net\MediaInfo,
Programs\MediaInfo, Programs\MediaArea\MediaInfo öğesini kontrol eder. Okunamayan konumlar ve uyumsuz DLLs
atlanır. Diski yinelemeli olarak taramaz.

Uyumlu bir harici DLL bulunamazsa, görüntüleyici yerleşik sürümleri şu sırayla dener: 26.10, 21.03, 0.7.60.
Her seferinde bir sürümü çıkarır ve test eder. Bir sürüm başarılı bir şekilde yüklendikten sonra eski sürümler
ne çıkarılır ne de test edilir. MediaInfo.exe'ün tek başına dağıtılması yeterlidir; uyumlu bir harici DLL her
zaman önceliklidir ve bağımsız olarak güncellenebilir.

Başarısız bir manuel kitaplık değişikliği, önceden yüklenmiş olan kitaplığı korur.

## Raporu dışa aktarma

Farklı Kaydetme formatları TXT, BMP, GIF, JPEG, PNG, TIFF ve WebP şeklinde sıralanmıştır. Desteklenmeyen
kodlayıcılar hem modern hem de eski iletişim kutularından çıkarılır.

TXT; ANSI, UTF-8, BOM içeren UTF-8, BOM içeren UTF-16 BE ve BOM içeren UTF-16 LE seçeneklerini sunar. İkinci
seçenek olan BOM içermeyen UTF-8 varsayılandır. Raporun tam metni ve özgün satır sonları korunur.

BMP, PNG ve TIFF oluşturulan tüm renkleri korur; GIF89a, görüntüde en fazla 256 renk bulunduğunda oluşturulan
paletin aynısını korur. Dışa aktarma her zaman seçilen formatı yazar veya bir hata bildirir; asla başka bir
formatın yerini almaz.

Resimler, beyaz zemin üzerine siyah metinle birlikte, seçilen rapor yazı tipinde tam raporu içerir. Uygulama
menüsünü, sekme başlıklarını, durum çubuğunu, seçimi veya düzeltme işaretini içermezler. Oluşturma, metin
kutusunun kaydırma konumundan bağımsızdır.

Raporların sessizce kesilmesini veya eski bilgisayarlarda adres alanının tükenmesini önlemek için, tek bir
görüntü 16.384 piksel genişliğinde, 32.767 piksel yüksekliğinde ve 256 MiB sıkıştırılmamış bitmap belleğiyle
sınırlıdır. Rapor bu sınırları aşarsa daha küçük bir yazı tipi seçin.

`Google WebP (*.webp)` son biçimdir ve raporu kayıpsız kaydeder.

WebP: 16383 × 16383 px.

## Arayüz ve rapor dilleri

Tercihler (Ayarlar > Tercihler, Ctrl+G), kitaplık yollarını, rapor yazı tipini, yumuşatmayı ve dilleri içerir.
Arayüzün 36 seçeneği vardır ve başlangıçta Windows’u izler. Raporların varsayılan dili, Windows ve arayüzden
bağımsız olarak her zaman kitaplığın özgün İngilizcesidir. Bunu yalnızca elle yapılan rapor dili seçimi
değiştirir: İngilizce, 37 çeviri veya özel MediaInfo CSV tablosu.

Tamam veya Uygula değişiklikleri onaylar; İptal bekleyen değişiklikleri atar. Tercihler, sekme adı sınırını
(varsayılan 80) ayarlar ve son dosyalar listesini temizler. Uzun adlar başlangıcı, sonu ve uzantıyı korur;
ortada üç nokta bulunur.

Varsayılan olarak yalnızca tek örneğe izin verilir ve sonraki başlatmalar dosyaları açık pencereye gönderir.
Tercihlerde birden fazla örneğe izin verilebilir. Birden fazla pencere olduğunda, her formun yalnızca ilk
penceresi kayıtlı konumunu geri yükler; sonraki pencereler yalnızca boyutu geri yükler.

Yalnızca arayüzün değiştirilmesi, açık raporların metnini değiştirmeden bırakır. Manuel olarak uygulanan bir
rapor dili değişikliği, sekme sırasını ve MRU sırasını korurken raporlarını yeniden yükler.

## libcurl

Seçilen MediaInfo DLL, ardından paylaşılan executable/ancestor, Program Dosyaları ve kullanıcı yükleme
konumlarının yanında otomatik curl keşif kontrolleri. Uyumlu bir harici curl bulunamazsa, eşleşen yerleşik
mevcut veya XP sürümü, kontrol edilen kullanıcı başına önbelleğe çıkarılır. En eski MediaInfo 0.7.60, curl
keşfini, çıkarılmasını ve yüklenmesini tamamen atlar. Açıkça seçilen geçersiz bir curl tercih değişikliğini
reddeder; isteğe bağlı otomatik curl'in eksik olması sıradan yerel dosya raporlarını engellemez.

## Dosya adları ve son kullanılan dosyalar

MRU dosya adları yalnızca 80 UTF-16 kod birimlerinden uzun olduğunda kısaltılır. Ortadaki üç nokta, dosya
adının uzantısından önceki başlangıcını, sonunu ve son uzantının tamamını korur; tam yollar ve raporlar
değişmeden kalır. Sekme başlıkları, yapılandırılabilir varsayılan 80 sınırıyla aynı algoritmayı kullanır.

Son dosyalar > Temizle, tüm açık sekmeleri olduğu gibi bırakarak hem canlı MRU menüsünü hem de kayıtlı
yollarını hemen temizler. Bekleyen tercihleri uygulamaz veya doğrulamaz ve Uygula seçeneğini etkinleştirmez.
İptal veya Kaçış, bekleyen düzenlemeleri atarken temizlenen geçmişi korur. Liste boş olduğunda Temizleme devre
dışı bırakılır ve liste yeni raporlar doldurulduğunda durumu yenilenir. Kayıt defteri yazma hatası hemen
bildirilir. Yeni bir sekme adı sınırı uygulamak, medya raporunu yeniden yüklemeye gerek kalmadan her açık
sekmeyi günceller.

## Lisans ve yeniden dağıtım

Görüntüleyici, license.txt'deki MIT Lisansı kapsamında lisanslanmıştır.

MediaInfo üçüncü taraf bir bileşendir. Bakımı yapılan tek dağıtım bildirimi, CRLF ile UTF-8 olarak kodlanmış
ve görüntüleyiciyi, kitaplıkları, statik olarak birleştirilmiş bileşenleri, simgeyi ve resmi çeviri
tablolarını içeren kök license.txt'dir.

Bu ürün MediaInfo kitaplığını kullanır, Telif Hakkı (c) 2002-2026 MediaArea.net SARL.

- MediaInfo: <https://mediaarea.net/MediaInfo>
- Lisans: <https://mediaarea.net/en/MediaInfo/License>
- Windows indirmeler: <https://mediaarea.net/en/MediaInfo/Download/Windows>

## Bağımlılıklar

### Dosyalar

| Kaynak | Mimarlık | Bileşen tarafından bildirilen sürüm | SHA-256 |
| --- | --- | --- | --- |
| Resources/lib/26.10/MediaInfo.dll | x86 | 26.10 | E73027A1577084135425AA013D46C8B2985AD142CCF04F1ADB301B9A9CFB78F8 |
| Resources/lib/21.03/MediaInfo.dll | x86 | 21.03 | EBBF1C371702F3DC39CA23D619C47EDF97E66A95AEABE725284F1402D8F3E58A |
| Resources/lib/0.7.60/MediaInfo.dll | x86 | 0.7.60 | A26C07BCC25FA01A40E6888D02EABD59AA8DB2ABF6F5195481228D3A91D04441 |
| Resources/lib/26.10/libcurl.dll | x86 | 8.11.0-DEV, Schannel, zlib 1.3.1 | DCF136C84F3A4FBEAE2B317FE36D7F11225B56FBA3343AF4BBA8706B3F46F334 |
| Resources/lib/21.03/libcurl.dll | x86 | 7.47.1, WinSSL, zlib 1.2.8 | 21025CAC8089F1E570EE083D8CFD6311C2C51E97094A9FCD8C7A0B544C22CB48 |
| Resources/lib/libwebp.dll | x86 | 1.1.0 | 9986023BB6FF5510A157919F0CD958A94800EC6A1D981F3403A9648BEDFEE575 |

Tablodaki yollar MediaInfo proje dizinine göredir.

Geçerli kitaplık bir geliştirme sürümünü rapor eder; tam kaynağı commit bu sürüm dizesinden kurtarılamaz.
Ekteki bildirimde, lisans koşulları geliştirme serisinde de mevcut olan yukarı yöndeki 8.11.0 telif hakkı ve
izin metni kullanılmaktadır.

### Dâhil edilen bileşenler

| Bileşen | Kanıt ve kapsam | Fark etme |
| --- | --- | --- |
| MediaInfoLib | Gerçek sürümler ve gerekli Unicode dışa aktarımları; değişmeden sağlanan ikili dosyalar | Sürüme özel orijinal telif hakkı, yeniden dağıtım koşulları ve sorumluluk reddi beyanı |
| ZenLib | Statik proje referansları ve üç DLLs'nin tamamında yerleşik ZenLib RTTI; tam bağlantılı revizyonlar sağlanmadı | zlib tarzı ZenLib bildirimi |
| zlib | Gömülü inflate/deflate sürüm dizeleri: MediaInfo içinde 1.3.2 26.10, 21.03 içinde 1.2.11, 0.7.60 içinde 1.2.7; curl ek olarak 1.3.1 ve 1.2.8 rapor eder | Beş sürümün tümü için orijinal zlib bildirimleri |
| TinyXML-2 | Modern kaynak hedeflerini ve ikili RTTI'yi eşleştirme; eski projeye dahil edilmiş, ancak çıkarılmış eski ikili dosyada bağımsız olarak tanımlanmamış | Orijinal Lee Thomason zlib tarzı bildirim korundu |
| Brian Gladman AES | Eşleşen izin verici kaynak bildirimleriyle birlikte her iki modern yukarı akış kitaplık hedefine dahil edilmiştir | 1998–2013 yeniden dağıtım bildirimi ve sorumluluk reddi beyanı |
| Brian Gladman SHA-1/SHA-2 | Hem modern hedefler; SHA-256 ve SHA-512 sabit tabloları her iki modern ikili dosyada da mevcut | 1998–2010 yeniden dağıtım bildirimi ve sorumluluk reddi beyanı |
| Brian Gladman HMAC | Hem modern hedefler hem de onların curl/S3 okuyucu kodları | Alternatif lisans paragrafı da dahil olmak üzere orijinal üç koşullu bildirim |
| MD5 | Modern kaynak hedefleri; Colin Plumb uygulaması açıkça kamuya açık alanı belirtiyor | İlişkilendirme korundu |
| Base64 | Karşılık gelen üç kaynak ağacının tümünde Markus Ewald başlığı, Bob Withers'e atıfta bulunulur | Orijinal yazarlık özelliği korundu; aşağıdaki yeterlilik |
| fmt | İkili dosyada 26.10 hedefi ve fmt v11 format_error RTTI | İsteğe bağlı istisna dahil orijinal MIT bildirimi |
| tfsxml | 26.10 kaynak hedefi | Orijinal MediaArea MIT bildirimi |
| Android JNI arayüzü | JNI_OnLoad aslında hem modern DLLs tarafından dışa aktarılır; dahil edilen JNI başlığı AOSP'dendir | AOSP telif hakkı ve eksiksiz Apache Lisansı 2.0 |
| libcurl | Sağlanan x86 ikili dosyaları; gerçek sürüm aktarımları; modern MediaInfo tarafından dinamik olarak kullanılır | 8.11.0 ve 7.47.1 için orijinal curl bildirimleri |
| Resmî rapor çevirileri | MediaInfo v26.10 dil dizinindeki tüm 38 değiştirilmemiş CSV kaynakları; 37 İngilizce olmayan tablolar gömülüdür, İngilizce ise DLL varsayılanlarını kullanır | Aynı proje BSD-2-Clause bildirimi birleştirilmiş bildirimde tutuldu |
| MediaInfo simgesi | Değiştirilmemiş resmi çoklu görüntü simgesi, kaynak revizyonu f057dd3649bc8692a83863b67770e22c9b9dd81a | Orijinal BSD-2-Clause bildirimi ve atıf |
| libwebp | WebPEncodeLosslessBGRA, WebPFree; 1.1.0; x86 | BSD-3-Clause; PATENTS |

Eşleşen kaynak hedefleri, bu yukarı yöndeki yapı yapılandırmalarına dahil edilmeyi sağlar; satıcı ikili
dosyalarındaki her işlevin optimizasyondan sağ çıktığını kanıtlamazlar. Revizyonu bu ikili dosyalara
kaydedilmeyen bağımlılıklar için tam sürüm talebinde bulunulmaz.

### İsteğe bağlı bileşenler ve sistem kitaplıkları

- Windows kütüphane projeleri, MediaInfo 26.10 ve 21.03 için çalışma zamanı yüklü libcurl'yi etkinleştirir.
  MediaInfo 0.7.60, MEDIAINFO_LIBCURL_NO ile oluşturuldu; ikili dosyası aynı zamanda devre dışı bırakılmış
  destek teşhisini de içerir. Görüntüleyici, bu paketlenmiş sürüm için curl'i hiçbir zaman keşfetmez, çıkarmaz
  veya yüklemez.
- libmms, sağlanan üç Windows DLLs'de de devre dışıdır, yerleşik devre dışı destek mesajlarıyla da
  onaylanmıştır. Yeniden dağıtılmıyor.
- Qt ve wxWidgets isteğe bağlı GUI yapılarına aittir. Hiçbiri bu görüntüleyiciye veya bu DLL bağımlılıklarına
  dahil değildir. Genel girişleri görüntülenen lisanstan kaldırıldı.
- Graphviz, modern yukarı akış kodunda isteğe bağlı bir çalışma zamanı kancasıdır. Hayır Graphviz DLL yeniden
  dağıtılmaz.
- Hiçbir FFmpeg eklentisi yeniden dağıtılmaz.
- MediaInfo DLLs doğrudan yalnızca KERNEL32.dll'yi içe aktarır. Bu, statik olarak bağlantılı çalışma
  zamanlarının ve yardımcı kodlarının olmadığı anlamına gelmez.
- Mevcut curl doğrudan WS2_32.dll, bcrypt.dll, ADVAPI32.dll, CRYPT32.dll ve KERNEL32.dll'yi içe aktarır. XP
  curl doğrudan WS2_32.dll, WLDAP32.dll, ADVAPI32.dll ve KERNEL32.dll'yi içe aktarır. Bunlar Windows
  bileşenleridir. Kullanılabilirlikleri Windows yükleyici tarafından kontrol edilir.
- Curl, Windows Schannel/WinSSL rapor eder, OpenSSL yapısını değil. Bildirilen ek sıkıştırma bağımlılığı zlib
  statik olarak eklenmiştir. Doğrudan içe aktarma tablosunda Windows DLL olmayan ek harici bir öğe görünmüyor.
- Görüntüleyicinin kendisinin C/C++ çalışma zamanı bağımlılığı yoktur. Sağlanan üçüncü taraf DLLs kendi
  derlenmiş çalışma zamanı bölümlerini içerir. Windows yapıları Microsoft araçlarını kullanır; jenerik
  libstdc++ veya libc++ envanter girişlerini gerektiren hiçbir kanıt yoktur.
- JPEG dinamik olarak yüklenen GDI+ sistemini kullanır. C# kaynak paketleyicisi ve PowerShell derleme
  araçlarıdır ve çalışma zamanı bağımlılıkları değildir.

Sıradan yerel dosya incelemesi, bir MediaArea sunucusuna veya uzaktan indirilen bir format veritabanına
ihtiyaç duymaz. libcurl, MediaInfo tarafından URL girişleri ve desteklenen medya formatlarındaki uzak
referanslar için kullanılır. Paketlenmesi, bu görüntüleyiciye ayrı bir URL açma komutu eklemez.

### Lisans depolama ve sınırlamalar

Bakımı yapılan tek dağıtım bildirimi [license.txt](../license.txt) olup, CRLF ile UTF-8 olarak kodlanmıştır.
İşaretlenen BSD, curl, zlib, MIT ve Apache yeniden dağıtım maddeleri, her DLL yanında fiziksel olarak ayrı bir
bildirim dosyası gerektirmez; birleşik bildirim, yürütülebilir ve dağıtım materyallerinde bunlara eşlik eder.

Arşivlenen MediaInfo 0.7.60 paketi kendi sürüme özel lisansını kullanır ve eski GNU Library GPL metnini
içerir. Şartları, değiştirilmemiş ikili yeniden dağıtımı değiştirilmiş sürümlerden açıkça ayırmaktadır; Bu
görüntüleyici tarafından yapılan dinamik bağlantı, sağlanan DLL öğesini değiştirmez. Orijinal koşulları ve
beraberindeki lisans metni korunur. İzleyici MIT lisanslı kalır.

Bir yukarı akış atıfının niteliklendirilmesi gerekir: Markus Ewald Base64 başlığının açık bir izni veya lisans
beyanı yoktur. MediaArea, ilgili MediaConch belgelerinde Bob Withers Base64 uygulamasını kamu malı olarak
tanımlar, ancak bu, her Ewald değişikliği için bağımsız olarak bir lisans verilmesini sağlamaz. O başlık için
hiçbir lisans tahsisi icat edilmedi. Bu kaynağın tam satıcı onayı, tam ZenLib revizyonları ve curl
geliştirmesi commit sağlanan ikili dosyalarda mevcut değildi. Bu noktalar, bu envanterin eksiksiz, bağımsız
olarak onaylanmış bir SBOM olarak ele alınmasını engeller.

### Birincil kaynaklar

- [MediaInfo yeniden dağıtım şartları](https://mediaarea.net/en/MediaInfo/License)
- 
  [MediaInfo 26.10 kitaplık hedefi](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Project/MSVC2022/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 21.03 kitaplık hedefi](https://github.com/MediaArea/MediaInfoLib/blob/v21.03/Project/MSVC2015/Library/MediaInfoLib.vcxproj)
- 
  [MediaInfo 0.7.60 kitaplık hedefi](https://github.com/MediaArea/MediaInfoLib/blob/v0.7.60/Project/MSVC2005/Library/MediaInfoLib.vcproj)
- 
  [Çalışma zamanı curl yükleyici](https://github.com/MediaArea/MediaInfoLib/blob/v26.10/Source/MediaInfo/Reader/Reader_libcurl.cpp)
- 
  [Paketlenmiş yardımcı kaynaklar ve bunların bildirimleri](https://github.com/MediaArea/MediaInfoLib/tree/v26.10/Source/ThirdParty)
- [ZenLib bildirimi](https://github.com/MediaArea/ZenLib/blob/master/License.txt)
- [zlib kaynak bildirimleri](https://github.com/madler/zlib/blob/v1.3.2/zlib.h)
- [curl 8.11.0 bildirimi](https://github.com/curl/curl/blob/curl-8_11_0/COPYING)
- [curl 7.47.1 bildirimi](https://github.com/curl/curl/blob/curl-7_47_1/COPYING)
- [Apache Lisansı 2.0](https://www.apache.org/licenses/LICENSE-2.0)
- [MediaArea Base64 açıklaması](https://github.com/MediaArea/MediaConch/blob/master/README.md)

Rapor tabloları <https://github.com/MediaArea/MediaInfo/tree/v26.10/Source/Resource/Plugin/Language>
adresinden gelir. Eşleşen proje LICENSE <https://github.com/MediaArea/MediaInfo/blob/v26.10/LICENSE> 'dir.

- [libwebp 1.1.0 COPYING](https://github.com/webmproject/libwebp/blob/v1.1.0/COPYING)
- [libwebp 1.1.0 PATENTS](https://github.com/webmproject/libwebp/blob/v1.1.0/PATENTS)
