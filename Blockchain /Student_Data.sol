// SPDX-License-Identifier: MIT
pragma solidity >= 0.7.0;

contract Student_management
{

	struct Student
    {
		int stud_id;
		string Name;
		string Department;
	}

	Student[] Students;

	function add_stud(int stud_id, string memory Name, string memory Department) public
    {
		Student memory stud = Student(stud_id, Name, Department);
		Students.push(stud);
	}

	function getStudent(int stud_id) public view returns(string memory, string memory)
    {
		for(uint i = 0; i < Students.length; i++)
        {
			Student memory stud = Students[i];
			if(stud.stud_id == stud_id)
            {
				return(stud.Name, stud.Department);
			}
		}
        return("Name Not Found", "Department Not Found");
	}

	//Fallback Function
    //It is executed whenever the contract receives plain Ether without any data
	fallback() external payable
    {
		Students.push(Student(7, "XYZ", "Computer Science"));
	}
    // the fallback function simply sends a message to the sender of the transaction to let them know that the transaction was received. 
    receive() external payable
    {
	}

    // When ether is sent to a contract with no calldata.
}
