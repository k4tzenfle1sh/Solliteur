using namespace std;
struct Log_Cards {
	int power; //мощность карты
	std::string lear; //масть карты

	/*вообще нужно это сделать как отдельную структуру как сущности карта, но потом*/
	int old_axis_x; //старые координаты х у до перемещения
	int old_axis_y;

	int new_axis_x; //новые координаты х у после перемещения
	int new_axis_y;

	Log_Cards()
	{}

	Log_Cards(int xx, string yy, int aa, int bb, int cc, int dd)
	{
		power = xx;
		lear = yy;

		old_axis_x = aa;
		old_axis_y = bb;

		new_axis_x = cc;
		new_axis_y = dd;

	}
};
struct Card_Deck {
	int power;
	std::string lear;
	bool is_Find_Already = false;

	double x = NAN;
	double y = NAN;
	Card_Deck()
	{}

	Card_Deck(int xx, string yy, bool zz, double aa, double bb)
	{
		power = xx;
		lear = yy;
		is_Find_Already = zz;

		x = aa;
		y = bb;
	}
};

struct Pattern { //первичный вектор
	int line;
	int column;
	int power;
	std::string lear;
	Pattern(int l, int c, int p, string lr) :line(l), column(c), power(p), lear(lr)
	{}
};
struct Main_Pattern { //основная запись поля
	int power;
	std::string lear;
	Main_Pattern()
	{}

	Main_Pattern(int xx, string yy)
	{
		power = xx;
		lear = yy;
	}
};
struct Deck { //когда-то было нужно для определения вершин поля хз нах он сейчас
	std::string name;
	Deck()
	{}

	Deck(string xx)
	{
		name = xx;
	}
};
struct House { //запись дома
	int power;
	std::string lear;
	House()
	{}

	House(int xx, string yy)
	{
		power = xx;
		lear = yy;
	}
};

struct Free_Cells { //запись деки
	int power;
	std::string lear;
	Free_Cells()
	{}

	Free_Cells(int xx, string yy)
	{
		power = xx;
		lear = yy;
	}
};

struct SaveFree_Cells { //попытка починить учечку памяти из деки
	int power;
	std::string lear;
	SaveFree_Cells()
	{}

	SaveFree_Cells(int xx, string yy)
	{
		power = xx;
		lear = yy;
	}
};

struct A_card { //запись выбранных карт
	int power;
	std::string lear;
	int x;
	int y;
	A_card()
	{}

	A_card(int xx, string yy, int A_x, int A_y)
	{
		power = xx;
		lear = yy;
		x = A_x;
		y = A_y;
	}
};

struct Free_column { //запись свободных столбцов на поле
	int count;
	Free_column()
	{}
	Free_column(int xx)
	{
		count = xx;
	}
};


std::vector<Pattern> new_pattern; //сам вектор
std::vector<Log_Cards> log_file; //вектор для записи ходов


int column; //для инициализации чтения из файла и записи в вектор
int line;
int power;
int count_leer = 0;
int count_free_column = 0;
int count_empty_card = 0;
int x = 0;
//флаг нужной масти
bool check = false;
bool if_column_from_deck = false;
bool replace_card_into_house = true;
bool is_exist = false;
bool is_exist_deck = false;
bool not_allowed = false;
bool Main_Check = false;

std::string lear_output[4] = { "A","J","Q","K" }; //замена цифр
std::string lear; // масть
std::string null = { "0" }; //тупа ноль
std::string house_leer[4] = { "ch","pk","bb","tt" }; //масти дома
//std::string free_column[5];

Main_Pattern mass[20][8]; //основной массив поля
House sup_mass[4]; //массив дома
Free_Cells deck[4];
SaveFree_Cells SaveDeck[4];
A_card A[2];
Free_column free_column[5];
Card_Deck CD[52];