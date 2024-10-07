 //! \brief Задание 1. Поиск человека по фамилии.
 void Task1_FindPersonByLastName()
 {
 Person** people = CreatePeopleArray();
 for (int i = 0; i < PeopleCount; i++)
 {
 WritePerson(people[i]);
 }

 std::string lastName;
 std::cout << "Enter last name: ";
 std::cin >> lastName;
 int foundIndex = -1;

 // ВНИМАНИЕ: Здесь нужно реализовать логику поиска.

 if(foundIndex == -1)
 {
 std::cout << "Could not find a person by last name: " << lastName <<
std::endl;
 }
 else
 {
std::cout << "A person's last name "
<< lastName
<< " was found. Its index in the array is "
<< foundIndex
<< std::endl;
}
ClearPeople(people, PeopleCount);
}
