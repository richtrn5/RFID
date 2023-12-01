class People
{
private:
    char* ID;
    char* fname;
    char* lname;
public:

    People();
    void storeUID(char* tempUID);
    
    ~People();
};

People::People(): ID(" "), fname("  "), lname("  ")
{

}

People::~People()
{
}
