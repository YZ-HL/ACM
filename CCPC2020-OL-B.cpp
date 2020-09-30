#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 5000005
#define int long long
#define BLOCK_LENGTH 5000000
using namespace std;
bool isp_s[maxn], isp_l[maxn];
int t, n, k;
int table[] = {0, 838596693108, 2364728301248, 3823097653715, 5246155169981, 6643178394102, 8027049707812, 9388226084984, 10757376545189, 12090729942028, 13440410138110, 14755104304286, 16094247428837, 17401803981195, 18731223854764, 20026736125708, 21317781912884, 22632874242681, 23906303820299, 25233207382477, 26490958703868, 27802000335535, 29091051334023, 30300518132207, 31606727206204, 32890617377828, 34175431266959, 35413715855104, 36676553613240, 37961213897248, 39205525289667, 40436501824379, 41722190422309, 42984991779000, 44237164624767, 45485788090635, 46791192534993, 47925497972627, 49216153199757, 50455743121030, 51618831732546, 52960990849498, 54189519013285, 55386727412672, 56608857143864, 57924651992377, 59081508484896, 60320440111766, 61637252051789, 62835665189558, 64017959658854, 65271086020049, 66445887695063, 67704686021411, 68907121434101, 70158903049226, 71379301888909, 72548845804560, 73825301263594, 75038045864951, 76196821347705, 77469890655251, 78749937215637, 79850673089246, 81014003648421, 82280010445434, 83557228521433, 84678977639740, 85879510232380, 87246743784406, 88329735183791, 89539118085727, 90715812272693, 91901931611882, 93195554935021, 94373244548667, 95740977474843, 96805247568071, 97940738312290, 99135927597609, 100385468050143, 101536479029900, 102739815411419, 103996084944012, 105064821055590, 106482464732063, 107534073088026, 108726929986141, 109862403065096, 111279455731446, 112324029504549, 113490342913401, 114696151067225, 115913058971691, 117130183421589, 118177352757998, 119658978471360, 120633231686709, 121839592811651, 122996511010923, 124255024703640, 125201006481038, 126483797974539, 127549909040152, 129145694366357, 130060484786803, 131396096671020, 132457203914022, 133803121800957, 134685202583080, 136167077923029, 137371846107848, 138346755954632, 139614663301592, 140701266803520, 141989220176296, 143146843208371, 144273355553544, 145517640076189, 146748822127536, 147868893424923, 149284936191800, 150031424436501, 151426623923835, 152347997300663, 153724731687557, 154926025645540, 155961181184243, 157233962467634, 158251442815755, 159697656926328, 160772941867416, 161994272626133, 163076363401678, 164201195111815, 165454218988871, 166543118729111, 167605839279187, 169128322827135, 170163076973099, 171208721763383, 172458592225563, 173677789221887, 174658637627907, 175793478458888, 177348383466513, 177987747693773, 179307045235984, 180709088792387, 181796897017235, 182651200351383, 183916320530477, 185307262782123, 186259809199624, 187642072473270, 188777065874656, 189807297950587, 191260250841948, 192429822271719, 193264095362415, 194636180524245, 195819712328472, 197026580775694, 197914529347699, 199247280250582, 200186269171766, 201507588519260, 202774663160391, 203875404366431, 204984362252633, 206155708785785, 207241528040416, 208180014232236, 209574911845945, 210857203553443, 212001300854433, 212787542274646, 214004616484930, 215265805818499, 216479449337510, 217418404556099, 218666852753071, 220568725990439, 221381613203236, 222416914431794, 223302838191513, 224256815488667, 225884023502033, 226645423923202, 228110217203153, 229313810734714, 230352096252165, 231720987934262, 232777334416143, 233781990447907, 234901405584044, 235810296318988, 237528569607573, 238352716599656, 239595190871224, 240814910985589, 241751175158366, 243110546219849, 244288194798156, 245284368786996, 246486792315949, 247559654884936, 248559596385368, 250201665906968, 251008616620786, 251779019316130, 253312059170201, 254360673035648, 255759360742486, 256967469445477, 257961500860150, 258730683619957, 260684532670711, 261365357158202, 262582237320052, 263764461621326, 264859607280007, 266019754683806, 266831027745282, 268202656539940, 268977386815246, 270440619489175, 271118738216077, 272749018553927, 273145465860593, 275152019731786, 276560570103554, 277211509111296, 278781411279150, 279682752670423, 280942797205356, 281799405348664, 282521963594621, 284157001607438, 285158967757371, 286606037153251, 287039258940932, 289019719898918, 289857673832448, 291260396257324, 291897412321401, 292771458382916, 294417608863791, 295531664732344, 296372492979475, 298309483152494, 299208322247765, 299789734614167, 301228603455615, 303116861768915, 303135086656632, 304697912219629, 305507810459573, 307032459017382, 308020259903130, 308668992684563, 310416724718546, 312105660264442, 312339580466285, 313497147354680, 314617317080824, 315846591578154, 317495513343178, 318161191633110, 319710565124126, 320459664486560, 321850837468975, 323023208158597, 324160477102414, 324757978625343, 325964158025325, 326981374438873, 328311578686317, 329471797700753, 331102909544144, 331705310705648, 332385185596453, 334123304226530, 335388701837675, 336411645926969, 337345705120622, 338686074581456, 339671435515988, 340471644662432, 341997579949567, 343520389823348, 343973975363357, 345606528489117, 346732161918660, 347020986436525, 348836838297483, 350555506303717, 350832502459855, 352483534320744, 354046355482901, 354359295818264, 355368550349018, 356777720348721, 357436261987247, 359189477129434, 359888682809334, 361915819942909, 361782323784573, 363339294278648, 364287924057477, 365947964140055, 366990494856119, 367918993701594, 368042254007161, 370335903118361, 371055432070901, 373001619781497, 373601256686887, 374600875573129, 375530166854990, 377095974059488, 378209473669628, 379003329924586, 379990759511771, 380961136782547, 382878501254883, 383727269013913, 385314022146571, 386035419943671, 386498969194880, 388200090353490, 388656158797113, 390155088171794, 391541781333552, 392694002958733, 393665955259168, 395161988095734, 396123239241497, 397605920528254, 397825220068886, 399093690276881, 400639114200032, 402302490786785, 402305558668497, 404381819372538, 404995661364201, 405952377240030, 406562552300766, 408304227091133, 409417719539300, 410590765513883, 411879708160288, 412946003065110, 413764880999536, 415024674157607, 415787640902255, 417605993288422, 418518466320679, 419388694373119, 421166032994044, 422329725015754, 422655536313191, 424034277549427, 424759244861002, 426060132207435, 427200030920365, 428302098832643, 429809532527128, 430625490742678, 431821361911865, 432388543185222, 433846199666797, 435321091794963, 436180523260615, 437182119367636, 438551314123824, 439552963997326, 440036325677471, 442307842431315, 442907499422569, 444569694118240, 445253716060452, 445948814794395, 447270725013409, 448321043547865, 449282743386167, 450794380765495, 452042455718474, 452783555420239, 454109989122124, 455409174720699, 456874738326599, 457379622511119, 458348040192727, 459626119287953, 461340613953184, 461779834067761, 463288198900651, 464105341423468, 465450425757951, 465507305913939, 468636562216026, 468923552139796, 470231457664971, 470900371280976, 471475103661287, 472581420983760, 474940854308739, 474809404263095, 476141946947281, 477896871452871, 478579210434901, 478884931298075, 481200386012315, 481595535680192, 483050661651272, 484041122503280, 485374360827283, 486456881523087, 487605039066053, 488232369248717, 490696121565509, 490912846176838, 492740501836650, 492998702361531, 493487860990573, 494633168542671, 495595526277427, 496881580840125, 499170132580565, 500036213561852, 501157937951386, 501636165967642, 503068286065505, 504045377550745, 505370946754308, 507036983213377, 506512676322099, 508762125563957, 509863948826167, 510520541023447, 510893818726603, 513402360950794, 513959102612490, 515307529395800, 515888562167109, 518027681892286, 518197121898897, 519860639412782, 520437123253757, 522316070686439, 523421821144190, 523713243691606, 525996944775589, 526867272374654, 529044939327189, 527686974111896, 528742988111993, 531854538014319, 532055122485275, 533130151774254, 533830162006444, 534435580581482, 537390390322435, 535912028144086, 539123741253489, 538974238670838, 540634325668215, 541918933302641, 542295578425583, 543746534422306, 545332889681264, 545945240060104, 546843506870088, 548950068667419, 549459241335673, 550434156131008, 552049676902354, 552649175560482, 553940144921174, 554815679113686, 555174719104984, 557403520704476, 558216399689019, 559533412995169, 560654185061798, 561963280469069, 562389055628572, 564530528938752, 564696213755684, 565249009164020, 567373444091343, 568335401795624, 568595960903400, 570949779335368, 572591515500528, 572391600675656, 574857397412094, 573649965525935, 576077094656242, 576361004114151, 577827806964518, 579891859507625, 580948138145695, 581542452219038, 582389479155734, 584272325477570, 585483875340866, 585954485469290, 586609855178980, 589025804751051, 589027704510023, 591130372190078, 591366785358943, 593292776124482, 593936607615037, 594680739999038, 595986738699357, 596879751665970, 598213720010726, 599401651813243, 599780331926965, 600324678480940, 602465585963911, 603671355548603, 604842507849152, 605086770832346, 607275002901724, 607105638214226, 608564935678841, 609761856444782, 611146900109058, 612677883893215, 613144948436829, 614376222772167, 615957982007276, 616735221317648, 617314924426023, 619691881863379, 619870176053253, 621441607668319, 622220477208827, 623496380891277, 624588333850231, 625644863156890, 625799565836684, 626449075850699, 628988614170626, 629688438461335, 630456138025034, 631372524496005, 633118751826266, 634306974129042, 635043428389364, 636760528288841, 638140491758484, 638961157220049, 639106602782204, 641453670390008, 641342219294194, 643189582737186, 644734681508155, 645486116946687, 646245828192594, 647605560799149, 649146446628330, 649807826395671, 650177974191646, 651305612191405, 652270991520197, 654768223174643, 655521833525168, 656207402933546, 657994057996307, 658429598204408, 659640824792306, 660265486132656, 661726806456993, 662510916059383, 663036009490876, 665227805453959, 666497881432633, 667341070945208, 667545278474754, 669157865668242, 670365671082405, 672373147191319, 672853464104355, 673331469307205, 674852729356749, 676433614645986, 676098306289118, 677646414522716, 679271593321200, 680729337914915, 680141221476051, 682784923985825, 683701844561902, 684943680673310, 685934231691234, 685207282560115, 688110188996743, 687875549896692, 691091550994218, 690669649254438, 691877183969523, 692416551245423, 695379435305865, 695861173796166, 697140239552564, 697432257803364, 698756775598645, 700366023923347, 701368185030928, 702880542798606, 704315620171128, 703892109691630, 705294544568968, 706386017552353, 706518590696514, 708580928058951, 708425440802110, 710697712125188, 712364167951276, 713250173954375, 714953056767932, 715337719181131, 715472318364741, 717025350621160, 718554259134579, 720056904507001, 721664344273412, 721207584815737, 723225924346532, 724479839813951, 724364133653590, 726109853543812, 726803698698271, 728678202781839, 728895258257117, 730705226922070, 732495284939732, 733170283895262, 733359191909125, 733775967334810, 736183239830509, 736680174377325, 738093186850205, 739095334876328, 740243960904030, 740988309094322, 743375016913761, 744423510294522, 743507534174487, 744411229620233, 746303329883755, 748393984337547, 749257194104770, 750108805643094, 750752546265299, 751631741282084, 754304486493250, 753950802800158, 755054362165949, 758513639236652, 757845829405187, 758652882908421, 760719646890043, 760155461738002, 761468211924276, 763367140785697, 764648281885159, 763126702899722, 767180855650734, 766937950487209, 768517660219408, 770126860162697, 769810010606890, 773051283213773, 772078740430284, 774289683836490, 775163786326164, 776296724055782, 777197183603076, 778496227521771, 780432161637308, 781703363275902, 780235109565464, 782694827382999, 784525349477418, 785026412577545, 786271800670278, 786681065734875, 789979746749973, 789022954637124, 789351738705653, 791914074524627, 792724853829701, 793464962912419, 794809393422820, 795722983523204, 797141133346556, 799159068303139, 799578489370686, 799759541987748, 801485011986241, 802167148617372, 803852369230601, 804352627995073, 805160228697190, 807116467072241, 808595198893009, 809648319023945, 808617349988098, 811817278882401, 810703207533627, 813122635511128, 814860426094620, 814782169710917, 814879841879788, 817808437398065, 818992624435994, 819237623202307, 818649665213180, 823487295090970, 823709137363179, 824825069140911, 824984415854006, 826094707382643, 828729869653579, 828835831440272, 829840504206582, 829188167257751, 830929789672375, 833820198523934, 834781335182944, 835090413729525, 834910625062712, 836613028477024, 837964976982157, 838940422283712, 839934114063616, 841127910392592, 842006123337989, 845169873419635, 845822395813183, 845993951998914, 847240113711996, 848075821634186, 849791015629903, 848992831230483, 850503927807118, 852152191277553, 853342187338488, 854958670924150, 854633331708395, 856710103528361, 857511149463287, 858258884298877, 859707029589634, 860532058002991, 862566468359370, 862908694294990, 863901141747897, 866545303352487, 865819374837986, 867224102740323, 868514017147572, 869274612475407, 868992436573467, 870846893410401, 872221051303574, 873971043008084, 874399957504660, 877643933118328, 876118410496827, 878575534819103, 880221012672855, 879749019687606, 880662642521046, 881942060832944, 884388848070965, 884918950380227, 884263430541802, 885668623204956, 886888726132177, 889236646310759, 889829972301382, 892497890254808, 891032636952233, 895036947235149, 894988705765878, 894197248217214, 897604971232689, 897063425120485, 898567950780067, 898345903336571, 901526205989478, 900955953612181, 902417219977418, 905018107708156, 905141351462754, 905554375412845, 906034667672735, 907910949030559, 910242880774346, 909876789007888, 911127188444786, 912482539979638, 913366098662811, 914978219018284, 916347508716457, 917822880478582, 918194128364505, 918737803205185, 919013404593109, 920695578763823, 922155599687086, 923219012734988, 924712184778237, 925341974965049, 926114865806330, 928853620998360, 928734358461322, 931650315285044, 931623084799597, 932596330917695, 935027930613392, 932054705422268, 935472338948019, 935622012302585, 938103165752189, 938098384693300, 938077239209968, 940046317572884, 941370199263901, 941499994995634, 944295476857695, 945357543769403, 945790766985641, 946918419981841, 950992321196306, 949203969172860, 950416335367120, 951366805272132, 953052081919258, 952718498457180, 955191010140708, 954242336897586, 957230729423491, 958694798709900, 958573162640078, 959095875360304, 961309086085809, 961672616625252, 964230713281165, 966423607226536, 965887986294139, 965909083162925, 966851095643618, 969249949676716, 968213390800377, 969428273799380, 972994390672972, 973915734875518, 973176573235114, 976681986102480, 977901835610533, 978128506496837, 977166316689530, 979435841769819, 981767898222376, 982502929961164, 983594886346462, 982835389986626, 985198214637651, 987441301170066, 986873495358289, 986898084951734, 988171300776844, 989622052269444, 991746714679921, 992445548790694, 996007495937750, 993372832275288, 994700313513512, 997352356255265, 997950714772004, 997141346434940, 999865229504114, 999580008772411, 1002240344355006, 1003784535897362, 1003866501329066, 1004070490868702, 1005408541061644, 1007012460846059, 1008382668073576, 1008951821606728, 1010591537773763, 1014357041463034, 1013697137524709, 1012321070148352, 1015343649453985, 1016383223621756, 1017223945580167, 1018252978681794, 1019726807894019, 1021291876770776, 1021162581595244, 1021045719239493, 1022773884263866, 1025510087933888, 1026224909186528, 1028413881964555, 1027395439609864, 1027442356838783, 1029848606653877, 1030504056591745, 1033216678234443, 1033517610182464, 1033454310162772, 1035991470588453, 1034670947081789, 1038018652102791, 1040737926737534, 1038957270923760, 1040955108916599, 1039202908182503, 1045509356702092, 1042955221881338, 1042452297972569, 1047746229580733, 1046726641107841, 1047914437044465, 1050284952657610, 1050795480412287, 1053590471313282, 1052372634319828, 1054254541217434, 1055152737902226, 1054596671451683, 1055717886620199, 1058630826905853, 1060230652768028, 1058586249203180, 1061290483709913, 1062124176415264, 1063611910061563, 1063837108602892, 1066700833027213, 1068941633877354, 1067339508570245, 1067494953640614, 1068458711413081, 1070242930376300, 1070126315597147, 1073331717120953, 1074085391557936, 1075264687014486, 1075330414102570, 1078324199668696, 1076890186674234, 1081416900010168, 1079909738062682, 1080225985292875, 1081649554661848, 1083542994060788, 1085303407411942, 1084822419113777, 1086348813545669, 1087818347973657, 1088939566801399, 1089492314482990, 1089960306055980, 1093646882587197, 1093213587518446, 1096941651051632, 1093802533828830, 1098126508633679, 1096035672959683, 1097610812168396, 1100746625591387, 1099374038274499, 1101145600990980, 1103161340024306, 1104247805736625, 1104698027528315, 1106819288400244, 1106768636142241, 1108176254938211, 1109810402489189, 1111159357486829, 1111103634510638, 1110906594856683, 1114535637192970, 1114795646568011, 1113434460134741, 1117109922397804, 1117560889808714, 1116226440180273, 1120314956293749, 1122395912361999, 1124168400124435, 1124516587461673, 1125095843503457, 1125244868299320, 1126575378985418, 1126113670799522, 1126333087607380, 1128948576670283, 1130725023231329, 1131853215258225, 1132481609052870, 1131957544837212, 1136732315999369, 1136054549355861, 1136792166879414, 1138729779741263, 1139339909290659, 1138179620586490, 1142756341225090, 1142082705625703, 1145660266308256, 1143792387173416, 1144971585456200, 1148083530214237, 1145805020601635, 1148775722240206, 1150402443085645, 1151418571798619, 1153309528834863, 1152912924422865, 1152782040127131, 1154626236571668, 1157093135843653, 1157885702692146, 1156724184866830, 1160532083867035, 1161931545780963, 1161007029204924, 1163393130766892, 1164210032604710, 1164212119786726, 1165714147023894, 1166518369706814, 1168613074301825, 1168197068580952, 1170339645011226, 1172789907770132, 1172680886295758, 1171459680560401, 1175493344837350, 1175020683099570, 1177838933637703, 1176073672693636, 1178079821367531, 1182841736961617, 1181280234204018, 1181090179253045, 1184383406000498, 1183348239328792, 1183063131507498, 1186190702384511, 1187674267403616, 1186087118103742, 1190626676212611, 1188752458676828, 1191377829447015, 1193594462927127, 1193568135522839, 1195298965668240, 1197728704070951, 1195011670170652, 1198106494785199, 1197981573608704, 1200769005771839, 1201713027676019, 1199753673305492, 1203082450262587, 1203864198858905, 1205838285718904, 1204190703197707, 1209141888562362, 1209651536171462, 1208778608323649, 1209996132006344, 1208725697794987, 1214106540991660, 1214248357476957, 1216099787284156, 1216654403779003, 1219091523751191, 1218514261530541, 1217552356352339, 1222731675717150, 1220096450025195, 1219653592449293, 1224442098951983, 1226283599431477, 1223650254687195, 1225708998350371, 1228425886864014, 1227843279355396, 1229452855284726, 1231472985559946, 1230405204708353, 1231489988605084, 1236546367396184, 1235479048977692, 1233930479343030, 1238539850179552, 1240066604852574, 1241182691680978, 1238680278675558, 1242433473834422, 1243359079484218, 1244908195341598, 1245470746409343, 1245075503910499, 1247794423436666, 1247817015960047, 1249120900924023, 1251812044274650, 1251679922688316, 1252220073702574, 1254330504580171, 1253271186036987, 1255798575805966, 1258023771982091, 1257342748732083, 1256737504298893, 1260015830314910, 1261214405237891, 1264300054448661, 1262295914943919, 1266406159469879, 1266464540900473, 1264649273426194, 1268027210033290, 1265961447019604, 1267922617528397, 1271972745396824, 1271127970125891, 1274968779747018, 1271019446377199, 1274414819606656, 1276083756302937, 1276714438823385, 1278865840233190, 1278623023220542, 1280161560694076, 1279206899169941, 1282046055108693, 1283043851161349, 1282054879565757, 1287116961808489, 1284391900377611, 1287262018566893, 1286531883660107, 1289648128010007, 1291624462677664, 1290891145299116, 1292728786443609, 1293514996622309, 1294568715095345, 1294946106355515, 1297579686619894, 1298948413336530, 1296163971856689, 1301758744756448, 1298803956528419, 1303733543575831, 1302905245609576, 1305536092750955, 1307341991386607, 1306750511021991, 1305450640277899, 1306601440812550, 1311157828276435, 1308035583896373, 1312350288135694, 1314678945775024, 1310458078468664, 1315679281243761, 1314611311822953, 1318850929010475, 1319156766996915, 1318255936114100, 1319769951932858, 1321932774523223, 1319973676029527, 1325519739289366, 1322065256693316, 1327135629773840, 1327077727262600, 1329450276764189, 1332918524284165, 1328320872728689, 1330317609324887, 1332182925113289, 1332669807500683, 1334332633438619, 1334732799423937, 1334097564741299, 1338133442538287, 1336200461534418, 1339147707752409, 1340155494276654, 1340999995622172, 1339587939938787, 1343424864970516, 1346219174371412, 1347093182641619, 1348094757841825, 1348028617711287, 1347801253987261, 1350516271684317, 1350931612528185, 1352333607187075, 1355023579580428, 1352167872335814, 1354698139534137, 1356363862843872, 1356990058500037, 1362771506966086, 1361738455975740, 1361936321027793, 1359615554264046, 1365533419391491, 1362243919500833, 1363867818858405, 1364884181314234, 1368752528034566, 1366508403967966, 1369826120350928, 1371220553103866, 1369702026852077, 1372833519384574, 1375292853926092, 1376217295354258, 1374684977794296, 1376227893897772, 1376602283236790, 1378283255192038, 1379205154932622, 1378724116495109, 1382935017974801, 1384019697239565, 1382426443939038, 1381934186074514, 1387505572193980, 1387106162941007, 1387512888896895, 1387129981640125, 1392940605594777, 1392644962217845, 1393935664864414, 1394088749567538, 1394405446437056, 1397415052746918, 1394875590888907, 1398158187668576, 1397902793954338, 1400350399350134, 1399807477029817, 1400990646760477, 1403415399543695, 1402196861070470, 1403557213273246, 1407037374112454, 1405611073286885, 1406151799287334, 1411125833516126, 1410898682152948, 1410973194237572, 1413049729159598, 1413665689075853, 1413400322251686, 1415395324500807, 1414141690292160, 1418820109326314, 1418319475332425, 1419906372789350, 1417555341483475, 1422166289078965, 1424013015281702, 1421241796513877, 1423839286539281, 1426833365471686, 1428391784779114, 1425427475268303, 1429213027873586, 1431915532232895, 1428463802783730, 1433076712423770, 1434227993900369, 1436521322419798, 1433023957737916, 1437543458121102, 1438935856543642, 1438716837617426, 1441489047980324, 1444199128986534, 1443704817428896, 1442888096600537, 1445227684189296, 1445511433803528, 1448408867139030, 1446796508070088, 1446428576240617, 1449006878752476, 1448598168147461, 1452766583927348, 1452639506698270, 1455263726426055, 1454903440188986, 1456068793500147, 1457036802452424, 1458030498024347, 1463530475343143, 1458702948477516, 1460389759868800, 1462427037612909, 1463235608848090, 1465115560795383, 1465227766616513, 1465801913162519, 1468885346525883, 1467527308200144, 1469031253955714, 1471592773309529, 1471233952749371, 1467982038191361, 1476558113474196, 1474915737052740, 1477169709923312, 1480153819674547, 1476647029284855, 1479771549758589, 1478077680475573, 1480937732006963, 1483370026429947, 1479314292528644, 1482733571136233, 1486277382761778, 1489118981605632, 1487174906694347, 1485443808604472, 1489620708757082, 1492608700647551, 1491843159415846, 1495090444782757, 1492801585565509, 1495083113855161, 1495631677988075, 1500925407297953, 1496605187253881, 1499739239894054, 1501672203583804, 1498428206361056, 1498372528953110, 1505206258946964, 1504253308067794, 1506040899190558, 1506748919537114, 1509491952124272, 1507290180807924, 1509501106079982, 1508696001932975, 1511619971885437, 1510893382576618, 1515740627872860, 1510820554507976, 1516027883947940, 1518492366691294, 1517100858886569, 1518541496507686, 1517109698045552, 1522035800382413, 1525706466582369, 1525867741741068, 1523621889051737, 1526106991660703, 1524983336447119, 1528439672663669, 1526703699275359, 1528276300965597, 1531911037922486, 1533556339467232, 1529915678554255, 1532768611975673, 1533968480330509, 1538615270878930, 1536396679348435, 1537066247885285, 1540409252454286, 1538027748974319, 1542315496147941, 1545629209623315, 1543193005842143, 1542490143429277, 1544340398858808, 1548563253600291, 1547344501918962, 1550083343062803, 1551327803220025, 1549182497664391, 1551064844943536, 1553412671680349, 1556764384670928, 1553468125299654, 1560420212550835, 1557761077591654, 1557111780319316, 1559974621478141, 1560503784966910, 1560260720365230, 1563891939374605, 1561988042131787, 1566559844287426, 1564454318627270, 1565355898619616, 1566933297469785, 1566597578056311, 1572883117643845, 1572227081358634, 1571917269354546, 1572805691177182, 1570899195279201, 1574415535719613, 1575095675160554, 1577519466532637, 1578049095304615, 1579738397903923, 1578989675397157, 1579738934877858, 1583655473011188, 1581394422350184, 1584738116220810, 1583270245836011, 1587409369861287, 1587481239135720, 1586338448095727, 1590181825621585, 1592814169588521, 1591494845400698, 1590810205911169, 1593139646803467, 1595689813219385, 1596588228541617, 1597595118143692, 1596897050619244, 1602085744690825, 1602280515473620, 1601012135218068, 1601544907820958, 1600059601734683, 1604204057024621, 1604692034560945, 1605923927130501, 1607893883480876, 1608811893151633, 1607426611046647, 1613538599421124, 1613088450047046, 1614864462159988, 1615276238278342, 1616671386092214, 1616635679436783, 1616097572662954, 1615645461149415, 1618288953724587, 1622591992244242, 1620821459799176, 1616833557944172, 1621883837258440, 1625227382528962, 1625501193481194, 1630755503736614, 1627568221615356, 1629245432999524, 1632902496030703, 1630742649324821, 1635581187995405, 1630338155033122, 1633641318428183, 1635432692025600, 1635871000188599, 1637097187313836, 1638523957433778, 1641159333536546, 1639621421620360, 1638660505469520, 1644350574500995, 1639534120624771, 1645446479944907, 1645229793262647, 1646965487548086, 1650170617222535, 1647260561736730, 1650782938330697, 1650764189835706, 1653328563080205, 1651617272598795, 1651579816290476, 1656636879958994, 1655470347784853, 1656116620890461, 1655669811157152, 1659604444232876, 1659216909079065, 1662913947886269, 1661897309162437, 1665053510561503, 1665071683256654, 1659578768725386, 1665632512304790, 1667853865725176, 1664344196565677, 1670667579661527, 1667631548004303, 1671892703027003, 1672634240577546, 1674334892883151, 1678474592732472, 1676082220479018, 1676280492647884, 1677675686992663, 1677780916861285, 1678480770639971, 1683212932217334, 1680247499681781, 1683758119053094, 1685055825131190, 1684066798877484, 1687867347132934, 1683981475429805, 1690258423870655, 1689926432592849, 1689008205790415, 1689110896796776, 1692952146457780, 1693996882594665, 1697756889343816, 1694362414642404, 1697932457849436, 1696966887598175, 1699936197128739, 1699873261955727, 1698902537137706, 1704038127834065, 1701708397437189, 1706468626493499, 1707421536486996, 1705955136854518, 1708117328215873, 1710600855110391, 1707627295934956, 1709315985741166, 1710287579524214, 1713319467888344, 1714238217059129, 1714344512972998, 1716105408942177, 1719682714414626, 1720359330206774, 1720494238235765, 1720722660869454, 1721303539152026, 1723216622684320, 1719642472663615, 1724351416853479, 1727533110530840, 1725531102203390, 1726478305089589, 1725849890719908, 1731123618002634, 1728979918729667, 1730540899800864, 1733414506311433, 1736795983529504, 1738519460538345, 1734110639707759, 1733853483063730, 1738243374160280, 1738667465420885, 1741263274540758, 1740400650676961, 1741822170560208, 1743697315472508, 1743083858046035, 1747602412198545, 1746837629794039, 1746636209830732, 1746519719442404, 1754858876016222, 1749979232573103, 1753064474336070, 1751803926738201, 1754219610937896, 1756412981158027, 1760352806216172, 1755762938366564, 1758165922994263, 1758243115623934, 1759387029298248, 1758675272703289, 1762100777415653, 1764444006556986, 1762459022470945, 1766509446598212, 1765141125081368, 1767300049698908, 1767967621948173, 1771179305780079, 1773705723037976, 1773429682311220, 1769803723086774, 1774094840688259, 1774988848077954, 1773531350302947, 1777090601372919, 1776905110854297, 1779770336318253, 1777138383965336, 1781345598341967, 1778252466822792, 1783390442153537, 1787734446476280, 1783887898259905, 1783481883214481, 1787088207577805, 1788167116367825, 1791271647767915, 1788068869567375, 1788623675155529, 1793873648271631, 1792718446759760, 1796836716074645, 1796743595269058, 1798742114790966, 1800586169457657, 1799547220566153, 1800873549565083, 1801573807603105, 1799815644965170, 1803699700696819, 1804761888872897, 1806533272149609, 1803216171556416, 1808575639528945, 1808218882403469, 1807297931611471, 1812979700357250, 1813795387737574, 1814403160318475, 1813933549287276, 1814348920654436, 1812333971400835, 1816886710117940, 1821310972406687, 1817564609328324, 1817810230661014, 1818796591350961, 1822295202564812, 1819509039080728, 1824884606685724, 1826621489195153, 1825355332852402, 1828135699433980, 1826850391292221, 1831245596870556, 1831446439923539, 1833921486225402, 1830814828899196, 1831480413144201, 1834099251648313, 1835630148591381, 1830806811211314, 1840194008740162, 1839735129462281, 1839426252889818, 1841395581117098, 1840149589429940, 1845673446492632, 1843052230407941, 1844845286426794, 1846191627188286, 1842819678223085, 1848371854240167, 1846499926627564, 1848217358092898, 1856199310534024, 1848912138251652, 1849461787419600, 1854529526862303, 1856827369928313, 1858270354074316, 1855390333090250, 1859337720354858, 1860712624337251, 1859186652660917, 1860372300871904, 1864420744484797, 1865711613087638, 1862721521339023, 1865469832997339, 1867262465248725, 1868116862146543, 1870868701160089, 1873485295840617, 1868495614508574, 1874802518035549, 1872752240143378, 1874711023841915, 1870306644259304, 1875207653689726, 1880413455749089, 1879875865670175, 1878364461322754, 1881581907801491, 1882537761144261, 1879420505475740, 1881562428752100, 1884809268283744, 1886023512486534, 1885803886883536, 1887751624174725, 1889337088809772, 1889020216354315, 1888226244614417, 1892095893481566, 1891283754443772, 1892219960754184, 1894212967407060, 1895399921026109, 1893592360734905, 1898852684792549, 1901240739347744, 1903491920929497, 1900643464311102, 1903695121096753, 1902096060956042, 1905619502229059, 1904775573683917, 1906024734758305, 1908147626660703, 1908907424986787, 1908907033065754, 1907077810388382, 1909752036326741, 1913198088464712, 1910461840811677, 1914734013422830, 1914869238010981, 1917120803125735, 1921084534052756, 1919110590079691, 1920062387521495, 1921796263243234, 1923135357390672, 1922034378139429, 1923257099890236, 1925865666224814, 1924575098187072, 1929920806069624, 1929238895716165, 1930181550946204, 1931821350059686, 1931710449486802, 1932296899421931, 1934141524313688, 1932805472578864, 1935190563428884, 1937115352600432, 1936067150003035, 1940506207151936, 1937644542955573, 1940494501461679, 1942244358842023, 1939409449717578, 1944533917088941, 1942569089225646, 1945432507963037, 1947568052167702, 1950551846912406, 1950554087725048, 1948920556896337, 1952425406144017, 1953114409228032, 1952030725672063, 1955789197870717, 1951727611629014, 1956143589203145, 1958409869731856, 1961575044616161, 1957763015870143, 1960875112256378, 1961866417522289, 1963010506045007, 1963175182987192, 1966589141755796, 1966752978743841, 1970234137310974, 1969729096508481, 1969583431000586, 1967044531799046, 1972027808517167, 1970478316540449, 1972328248683629, 1973897639361296, 1975186916972938, 1976422586383206, 1977159351697457, 1978594455757747, 1979067615759305, 1980447879361497, 1982483301391173, 1984392513070311, 1984401479303892, 1980730935821741, 1984578183452634, 1990653114492965, 1988890495929430, 1984662934908583, 1988726249205767, 1994090435452813, 1991901999721060, 1991583890330066, 1991813490438884, 1993112263358615, 1996371982548674, 1996472156882284, 1992967815427721, 1999091624645608, 2004852321380603, 1996825824658988, 1998657585162707, 2004130327170576, 2001274949622251, 2009108683068070, 2011240478404333, 2005284782768024, 2008953833671912, 2009057131378767, 2015277100436571, 2013543548782269, 2013673378166267, 2014865481111304, 2012866960160262, 2018312502272395, 2015571041891929, 2024727241719020, 2019841662105121, 2019661735395338, 2022336993159483, 2021505593476090, 2027767851501999, 2023376204986273, 2025274310099744, 2024298379699128, 2026661394635277, 2028923542432493, 2031297985066925, 2031111713618456, 2032220233568326, 2034400145698529, 2029580293873710, 2031993424665258, 2036436528252287, 2034879348835692, 2038082456443798, 2038721520500210, 2036635439839709, 2037506378935430, 2044904594591011, 2042842579967643, 2044860626629784, 2048166248062252, 2047470698270864, 2045655064777155, 2047457257716595, 2049007339997868, 2055481754766068, 2051071405752522, 2049962193530869, 2052408299391427, 2059630407263081, 2054499052565466, 2056768525062873, 2053271834757242, 2059020550352481, 2061405264028286, 2060667422564589, 2060448465751249, 2061783088121157, 2063610272142331, 2061719055719179, 2069839723200124, 2063967810790301, 2067240118307955, 2068099882182261, 2070661370369370, 2072378931118020, 2070838860775710, 2077728929378763, 2073728428210115, 2075912960647228, 2072573360764852, 2075301391923644, 2077323977007006, 2080744984379456, 2082464016176024, 2083380339695070, 2080726063283459, 2082358712923530, 2090068178642755, 2083421667178052, 2087164760765261, 2088329226745441, 2088726033976167, 2090457687510054, 2092035498841723, 2092017724621154, 2095126282839260, 2097466447435714, 2091254121793920, 2096117289852014, 2094486093637968, 2096952033507603, 2101899655703275, 2102795566362195, 2105062421781569, 2103328962077075, 2102085939600714, 2106220752963887, 2104916836579074, 2109936879182496, 2106897120246382, 2111340317439794, 2111875461077511, 2112711294387049, 2113964670913120, 2110690107623863, 2111863202914956, 2114203753769775, 2117314690190585, 2117204632841806, 2119276245325749, 2116932648181907, 2121598139999944, 2115884790845935, 2122162280180657, 2125622968177162, 2125020830194933, 2124083392043558, 2125366181078622, 2127401132620065, 2130142833061856, 2128281341710635, 2135582320477101, 2129384533747426, 2131029545445961, 2132547208832079, 2135716525603319, 2132793212156737, 2135127807835884, 2142754778169809, 2138115920034025, 2136326785937535, 2139273105458320, 2144321761400494, 2143052260979563, 2141780185627772, 2147940154465522, 2146173238294931, 2149039214212511, 2145913177238091, 2147127793723176, 2154497539045035, 2147624203935225, 2151086130534111, 2150973441806610, 2155935776511471, 2156476372939150, 2158596527633966, 2156872089032301, 2159508406075951, 2159530840615146, 2158617296509339, 2163862098797717, 2161613692314126, 2164781034780725, 2166775447604864, 2161758440156628, 2165038051149968, 2169197015440754, 2169834166936687, 2171999947168685, 2170077067792828};
void inits(int lim)
{
    memset(isp_s, true, sizeof(isp_s));
    for (int i = 2; i <= lim; i++)
    {
        if (isp_s[i])
        {
            for (int j = i * 2; j <= lim; j += i)
            {
                isp_s[j] = false;
            }
        }
    }
}
int Prime_Cnt(int s, int lim)
{
    memset(isp_l, true, sizeof(isp_l));
    for (int i = 2; i * i <= lim; i++)
    {
        if (isp_s[i])
        {
            int nows = max(2 * i, i * (s % i ? s / i + 1 : s / i));
            for (int j = nows; j <= lim; j += i)
                isp_l[j - s] = false;
        }
    }
    int sum = 0;
    for (int i = s; i <= lim; i++)
        if (isp_l[i - s])
            sum += i;
    return s == 1 ? sum - 1 : sum;
}
int solve(int lim)
{
    int s = 1, sum = 0, cnt = 0;
    while (s + BLOCK_LENGTH - 1 <= lim)
        sum = (sum + table[++cnt]) % k, s += BLOCK_LENGTH;
    if (s != lim + 1)
        sum += Prime_Cnt(s, lim), sum %= k;
    return sum;
}
signed main(void)
{
    scanf("%lld", &t);
    inits(100000);
    while (t--)
    {
        scanf("%lld %lld", &n, &k);
        int inv = ((k - k / 2) % k);
        int sum = ((((((n + 3) % k) * (n % k)) % k) * (inv % k)) % k);
        int ans = (sum + (solve(n + 1) % k)) % k;
        printf("%lld\n", (ans + k - 4) % k);
    }
    system("pause");
    return 0;
}
