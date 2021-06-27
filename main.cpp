#include <iostream>
#include "src/Method.h"

int main() {
    Rating r1("Biology");
    Rating r2("Chemistry");
    Rating r3("Physics");
    Rating r4("OBJ");
    vector<Rating> grades;
    grades.push_back(r1);
    grades.push_back(r2);
    grades.push_back(r3);
    grades.push_back(r4);

    //ученики
    Pupil uch1("Алексей", 12, grades);
    Pupil uch2("Леня", 17, grades);

    //предметы учителей
    vector<string> predmeti1;
    predmeti1.emplace_back("Biology");
    predmeti1.emplace_back("Chemistry");
    vector<string> predmeti2;
    predmeti2.emplace_back("Physics");
    predmeti2.emplace_back("OBJ");

    //учителя
    Teacher uchit1("Елисей", 20, predmeti1, 202);
    Teacher uchit2("Егор", 100, predmeti2, 304);


    //ставим оценки
    uch1 = uchit1.addGrade(uch1, 5, "Biology");
    uch1 = uchit1.addGrade(uch1, 4, "Biology");
    uch1 = uchit1.addGrade(uch1, 5, "Biology");
    uch1 = uchit1.addGrade(uch1, 3, "Chemistry");
    uch1 = uchit1.addGrade(uch1, 3, "Chemistry");
    uch1 = uchit1.addGrade(uch1, 2, "Chemistry");

    uch1 = uchit1.setSemesterGrade(uch1, "Biology");
    uch1 = uchit1.setSemesterGrade(uch1, "Chemistry");
    uch1 = uchit2.addGrade(uch1, 5, "Physics");
    uch1 = uchit2.addGrade(uch1, 4, "Physics");
    uch1 = uchit2.addGrade(uch1, 3, "OBJ");
    uch1 = uchit2.setSemesterGrade(uch1, "Physics");
    uch1 = uchit2.setSemesterGrade(uch1, "OBJ");

    uch1.print_grades();
    cout << endl;

    uch2 = uchit1.addGrade(uch2, 2, "Biology");
    uch2 = uchit1.addGrade(uch2, 3, "Biology");
    uch2 = uchit1.addGrade(uch2, 1, "Biology");
    uch2 = uchit1.addGrade(uch2, 5, "Chemistry");
    uch2 = uchit1.addGrade(uch2, 5, "Chemistry");
    uch2 = uchit1.setSemesterGrade(uch2, "Biology");
    uch2 = uchit1.setSemesterGrade(uch2, "Chemistry");
    uch2 = uchit2.addGrade(uch2, 4, "Physics");
    uch2 = uchit2.addGrade(uch2, 4, "Physics");
    uch2 = uchit2.addGrade(uch2, 3, "OBJ");
    uch2 = uchit2.addGrade(uch2, 5, "OBJ");
    uch2 = uchit2.setSemesterGrade(uch2, "Physics");
    uch2 = uchit2.setSemesterGrade(uch2, "OBJ");

    //класс
    vector<Pupil> ucheniki;
    ucheniki.emplace_back(uch1);
    ucheniki.emplace_back(uch2);
    SchoolClass A11("A11", ucheniki);

    //урок1
    Lesson_builder builder;
    builder.setSchoolclass(A11);
    builder.setSubject("Biology");
    builder.setTeacher(uchit1);
    builder.setTimeStart(1010);
    builder.setTimeEnd(1140);
    builder.setWeekday(MONDAY);
    Lesson urok1 = builder.build();

    //урок2
    builder.setSchoolclass(A11);
    builder.setSubject("Physics");
    builder.setTeacher(uchit2);
    builder.setTimeStart(830);
    builder.setTimeEnd(1000);
    builder.setWeekday(MONDAY);
    Lesson urok2 = builder.build();

    //расписание
    vector<Lesson> uroki;
    uroki.emplace_back(urok1);
    uroki.emplace_back(urok2);
    Schedule raspis(uroki);

    //школа
    vector<SchoolClass> klassi;
    klassi.emplace_back(A11);
    vector<Teacher> uchitelya;
    uchitelya.emplace_back(uchit1);
    uchitelya.emplace_back(uchit2);
    School shkola("MOANC", klassi, uchitelya, raspis);
    //............................................................................

    shkola.printGradesByClass(); // вывод всех оценок школы
    Schedule sch = shkola.getSchedule();
    sch.printSchedule(A11); // вывод рассписания класса
    sch.printSchedule(uchit1); // вывод рассписания учителя

    return 0;
}
