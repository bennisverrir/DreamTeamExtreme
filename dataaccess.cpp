#include "dataaccess.h"



dataAccess::dataAccess()
{

}
/*Function readFile,@param bool @return vector<Legend>
* Reads one line at a time from a file and generates a instance of Legend
* Then pushes the Legend instance into a vector and retuns a vector<Legend>.
* sets fileOpen to true if file is open and false if it could not be open
*/
vector<Legend> dataAccess::readFile(bool &fileOpen)
{
    ifstream file;

    vector<Legend> returnVector;

    file.open(fileName);
    string line;
    string name;
    char gender;
    int born;
    int death;

    if(file.is_open())
    {
        fileOpen = true;

        while(getline(file,line))
        {
            stringstream linestream(line);

            string sBorn;
            string sDeath;
            string sGender;

            getline(linestream, name, ',');
            getline(linestream, sGender, ',');
            getline(linestream, sBorn, ',');
            getline(linestream, sDeath, ',');

            born = atoi(sBorn.c_str());
            death = atoi(sDeath.c_str());
            gender = sGender[0];

            Legend tempLegend(name, gender, born, death);

            returnVector.push_back(tempLegend);

        }
    }
    else
    {
        fileOpen = false;
    }

    file.close();

    return returnVector;
}

/*Function writeFile, @param Legend and bool
* Takes a Legend and writes all information about it in a new line in a file
* sets fileOpen to true if file is open and false if it could not be open
*/

void dataAccess::writeFile(Legend writeLegend, bool &fileOpen)
{
    ofstream file;

    file.open(fileName, ios::app);

    if(file.is_open())
    {
        fileOpen = true;

        file << endl << writeLegend.getName() << "," << writeLegend.getGender() << ","
             << writeLegend.getBorn() << "," << writeLegend.getDeath();
    }
    else
    {
        fileOpen = false;
    }
    file.close();
}

/*Function deleteLine, @param vector<Legend> and bool
* Takes the @param which is a vector of all the Legend without the deleted Legend
* writes over the file the information of all the Legend in the vector into the file.
* sets fileOpen to true if file is open and false if it could not be open
*/
void dataAccess::deleteLine(vector<Legend> &deleteLegend, bool &fileOpen)
{
    ofstream file;

    file.open(fileName, ios::trunc);

    if(file.is_open())
    {
        fileOpen = true;

        for(size_t i = 0; i < deleteLegend.size(); i++)
        {
            file << deleteLegend[i].getName() << "," << deleteLegend[i].getGender() << ","
                 << deleteLegend[i].getBorn() << "," << deleteLegend[i].getDeath();

            if(i != (deleteLegend.size() - 1))
            {
                file << endl;
            }
        }
    }
    else
    {
        fileOpen = false;
    }

    file.close();

}
