// SPDX-License-Identifier: UNLICENSED
pragma solidity >= 0.7.0; 

contract Bank
{
    mapping(address=>uint)user_account;
    // Map the Account Address with the Account Balance
    mapping(address=>bool)user_exists;
    // Maps whether the Account Corresponding to an Address exists or Not

    function create_account() public payable returns(string memory)
    {
        // Check if the Account Already Exists
        require(user_exists[msg.sender]==false,"Account already exists ! ");
        user_account[msg.sender]=msg.value; // Assign Balance
        user_exists[msg.sender]=true;       // Add to Accounts
        return "Account Creation Successful!";
    }

    function deposit(uint amount) public payable returns(string memory)
    {
        // Check if Account Exists
        require(user_exists[msg.sender]==true, "Account Does not Exist!");
        // Amount to be Deposited Cannot be Negative
        require(amount>0, "Amount to be Deposited Cannot be Negative");
        user_account[msg.sender]+=amount;
        return("Amount Deposited Successfully");
    }

    function withdraw(uint amount)public payable returns(string memory)
    {
        // Check if Account Exists
        require(user_exists[msg.sender]==true,"Accout Does not Exist!");
        // Amount to be Withdrawn cannot be Negative
        require(amount>0,"Amount to be Withdrawn cannot be Negative");
        // Cannot Withdraw more than Account Balance
        require(amount<=user_account[msg.sender],"Insufficient Balance!");
        user_account[msg.sender]-=amount;
        return("Amount Deposited Successfully");
    }

    function show_balance() public view returns(uint)
    {
        return user_account[msg.sender];
    }
}
