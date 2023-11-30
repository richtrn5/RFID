class People
{
private:
    char* UID[15];
    char* ID[10];
    char* fname[15];
    char* lname[15];
public:

    People();
    void storeUID(char* tempUID[15])

    ~People();
};

People::People(): UID(""), ID(""), fname(""), lname("")
{

}

People::~People()
{
}
