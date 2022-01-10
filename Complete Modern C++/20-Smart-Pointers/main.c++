//
// Created by Vincent Morin on 2021-12-29.
//

#include <iostream>
#include <string>
#include <memory>

class Int {
    int* m_p;
public:
    explicit Int(int p): m_p{new int{p}} {}
    ~Int() {
        delete m_p;
    }

    int GetValue() {
        return *m_p;
    }
};

class Project {
    std::string m_Name;
public:
    void SetName(const std::string &name) {
        m_Name = name;
    }
    void ShowProjectDetails()const {
        std::cout << "[Project Name]" << m_Name << std::endl;
    }
};

class Employee {
    std::shared_ptr<Project> m_pProject{};
public:
    void SetProject(std::shared_ptr<Project> &prj) {
        m_pProject = prj;
    }
    [[nodiscard]] const std::shared_ptr<Project> GetProject()const {
        return m_pProject;
    }
};

void ShowInfo(std::shared_ptr<Employee>& emp) {
    emp->GetProject()->ShowProjectDetails();
}

int main() {

    // Section for unique ptr
    std::unique_ptr<Int> p{new Int{5}};
    std::cout << p->GetValue() << std::endl;

    // Section for shared ptr
    std::shared_ptr<Project> prj{new Project{}};
    prj->SetName("Video Decoder");

    std::shared_ptr<Employee> e1{new Employee{}};
    e1->SetProject(prj);

    std::shared_ptr<Employee> e2{new Employee{}};
    e2->SetProject(prj);

    std::shared_ptr<Employee> e3{new Employee{}};
    e3->SetProject(prj);

    prj->ShowProjectDetails();
    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);


    return 0;
}