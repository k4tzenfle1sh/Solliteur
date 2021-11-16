using namespace std;
struct Log_Cards {
	int power; //�������� �����
	std::string lear; //����� �����

	/*������ ����� ��� ������� ��� ��������� ��������� ��� �������� �����, �� �����*/
	int old_axis_x; //������ ���������� � � �� �����������
	int old_axis_y;

	int new_axis_x; //����� ���������� � � ����� �����������
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

struct Pattern { //��������� ������
	int line;
	int column;
	int power;
	std::string lear;
	Pattern(int l, int c, int p, string lr) :line(l), column(c), power(p), lear(lr)
	{}
};
struct Main_Pattern { //�������� ������ ����
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
struct Deck { //�����-�� ���� ����� ��� ����������� ������ ���� �� ��� �� ������
	std::string name;
	Deck()
	{}

	Deck(string xx)
	{
		name = xx;
	}
};
struct House { //������ ����
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

struct Free_Cells { //������ ����
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

struct SaveFree_Cells { //������� �������� ������ ������ �� ����
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

struct A_card { //������ ��������� ����
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

struct Free_column { //������ ��������� �������� �� ����
	int count;
	Free_column()
	{}
	Free_column(int xx)
	{
		count = xx;
	}
};


std::vector<Pattern> new_pattern; //��� ������
std::vector<Log_Cards> log_file; //������ ��� ������ �����


int column; //��� ������������� ������ �� ����� � ������ � ������
int line;
int power;
int count_leer = 0;
int count_free_column = 0;
int count_empty_card = 0;
int x = 0;
//���� ������ �����
bool check = false;
bool if_column_from_deck = false;
bool replace_card_into_house = true;
bool is_exist = false;
bool is_exist_deck = false;
bool not_allowed = false;
bool Main_Check = false;

std::string lear_output[4] = { "A","J","Q","K" }; //������ ����
std::string lear; // �����
std::string null = { "0" }; //���� ����
std::string house_leer[4] = { "ch","pk","bb","tt" }; //����� ����
//std::string free_column[5];

Main_Pattern mass[20][8]; //�������� ������ ����
House sup_mass[4]; //������ ����
Free_Cells deck[4];
SaveFree_Cells SaveDeck[4];
A_card A[2];
Free_column free_column[5];
Card_Deck CD[52];