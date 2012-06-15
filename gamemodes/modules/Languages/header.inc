/*!
 * Languages/header.inc
 *
 > Priority: 11
 */

// Save space (since these will be replaced for all translatable strings)
#define this.Prepare          _@lp
#define this.Strings          _@ls
#define this.ActiveLanguage   _@lc

const this.MAX_LANGUAGES = 20;

stock const this.LanguageCodes[][] = {
	{!"AB", !"Abkhazian"},
	{!"AA", !"Afar"},
	{!"AF", !"Afrikaans"},
	{!"SQ", !"Albanian"},
	{!"AM", !"Amharic"},
	{!"AR", !"Arabic"},
	{!"HY", !"Armenian"},
	{!"AS", !"Assamese"},
	{!"AY", !"Aymara"},
	{!"AZ", !"Azerbaijani"},
	{!"BA", !"Bashkir"},
	{!"EU", !"Basque"},
	{!"BN", !"Bengali, Bangla"},
	{!"DZ", !"Bhutani"},
	{!"BH", !"Bihari"},
	{!"BI", !"Bislama"},
	{!"BR", !"Breton"},
	{!"BG", !"Bulgarian"},
	{!"MY", !"Burmese"},
	{!"BE", !"Byelorussian"},
	{!"KM", !"Cambodian"},
	{!"CA", !"Catalan"},
	{!"ZH", !"Chinese"},
	{!"CO", !"Corsican"},
	{!"HR", !"Croatian"},
	{!"CS", !"Czech"},
	{!"DA", !"Danish"},
	{!"NL", !"Dutch"},
	{!"EN", !"English, American"},
	{!"EO", !"Esperanto"},
	{!"ET", !"Estonian"},
	{!"FO", !"Faeroese"},
	{!"FJ", !"Fiji"},
	{!"FI", !"Finnish"},
	{!"FR", !"French"},
	{!"FY", !"Frisian"},
	{!"GD", !"Gaelic"},
	{!"GL", !"Galician"},
	{!"KA", !"Georgian"},
	{!"DE", !"German"},
	{!"EL", !"Greek"},
	{!"KL", !"Greenlandic"},
	{!"GN", !"Guarani"},
	{!"GU", !"Gujarati"},
	{!"HA", !"Hausa"},
	{!"IW", !"Hebrew"},
	{!"HI", !"Hindi"},
	{!"HU", !"Hungarian"},
	{!"IS", !"Icelandic"},
	{!"IN", !"Indonesian"},
	{!"IA", !"Interlingua"},
	{!"IE", !"Interlingue"},
	{!"IK", !"Inupiak"},
	{!"GA", !"Irish"},
	{!"IT", !"Italian"},
	{!"JA", !"Japanese"},
	{!"JW", !"Javanese"},
	{!"KN", !"Kannada"},
	{!"KS", !"Kashmiri"},
	{!"KK", !"Kazakh"},
	{!"RW", !"Kinyarwanda"},
	{!"KY", !"Kirghiz"},
	{!"RN", !"Kirundi"},
	{!"KO", !"Korean"},
	{!"KU", !"Kurdish"},
	{!"LO", !"Laothian"},
	{!"LA", !"Latin"},
	{!"LV", !"Latvian, Lettish"},
	{!"LN", !"Lingala"},
	{!"LT", !"Lithuanian"},
	{!"MK", !"Macedonian"},
	{!"MG", !"Malagasy"},
	{!"MS", !"Malay"},
	{!"ML", !"Malayalam"},
	{!"MT", !"Maltese"},
	{!"MI", !"Maori"},
	{!"MR", !"Marathi"},
	{!"MO", !"Moldavian"},
	{!"MN", !"Mongolian"},
	{!"NA", !"Nauru"},
	{!"NE", !"Nepali"},
	{!"NO", !"Norwegian"},
	{!"OC", !"Occitan"},
	{!"OR", !"Oriya"},
	{!"OM", !"Oromo, Afan"},
	{!"PS", !"Pashto, Pushto"},
	{!"FA", !"Persian"},
	{!"PL", !"Polish"},
	{!"PT", !"Portuguese"},
	{!"PA", !"Punjabi"},
	{!"QU", !"Quechua"},
	{!"RM", !"Rhaeto-Romance"},
	{!"RO", !"Romanian"},
	{!"RU", !"Russian"},
	{!"SM", !"Samoan"},
	{!"SG", !"Sangro"},
	{!"SA", !"Sanskrit"},
	{!"SR", !"Serbian"},
	{!"SH", !"Serbo-Croatian"},
	{!"ST", !"Sesotho"},
	{!"TN", !"Setswana"},
	{!"SN", !"Shona"},
	{!"SD", !"Sindhi"},
	{!"SI", !"Singhalese"},
	{!"SS", !"Siswati"},
	{!"SK", !"Slovak"},
	{!"SL", !"Slovenian"},
	{!"SO", !"Somali"},
	{!"ES", !"Spanish"},
	{!"SU", !"Sudanese"},
	{!"SW", !"Swahili"},
	{!"SV", !"Swedish"},
	{!"TL", !"Tagalog"},
	{!"TG", !"Tajik"},
	{!"TA", !"Tamil"},
	{!"TT", !"Tatar"},
	{!"TE", !"Tegulu"},
	{!"TH", !"Thai"},
	{!"BO", !"Tibetan"},
	{!"TI", !"Tigrinya"},
	{!"TO", !"Tonga"},
	{!"TS", !"Tsonga"},
	{!"TR", !"Turkish"},
	{!"TK", !"Turkmen"},
	{!"TW", !"Twi"},
	{!"UK", !"Ukrainian"},
	{!"UR", !"Urdu"},
	{!"UZ", !"Uzbek"},
	{!"VI", !"Vietnamese"},
	{!"VO", !"Volapuk"},
	{!"CY", !"Welsh"},
	{!"WO", !"Wolof"},
	{!"XH", !"Xhosa"},
	{!"JI", !"Yiddish"},
	{!"YO", !"Yoruba"},
	{!"ZU", !"Zulu"}
};

new this.Strings[this.MAX_LANGUAGES][{#LANGUAGES_NUM_STRINGS#}][1];
new this.Descriptions[this.MAX_LANGUAGES][{#LANGUAGES_NUM_STRINGS#}][1];
new this.ActiveLanguage;
new this.CurrentPlayer;
new this.PreviousPlayer = INVALID_PLAYER_ID;
new this.PlayerLanguage[MAX_PLAYERS];
new this.Languages = 0;
new this.LanguageNames[this.MAX_LANGUAGES];
new this.TextBuffer[2048];

forward this.Prepare(forplayer = INVALID_PLAYER_ID);
forward this.GetStringIndex(const string[], &lang = 0);
forward this.CheckStringArgument(arg, playerid);