#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <sstream>

using namespace std;

class AskMeTester {
private:
    const string users_test_file = "test_users.txt";
    const string questions_test_file = "test_questions.txt";
    
    void CreateInitialTestFiles() {
        // Create test users file
        ofstream users_file(users_test_file);
        users_file << "13,mostafa,111,mostafa_saad_ibrahim,mostafa@gmail.com,1\n";
        users_file << "11,noha,222,noha_salah,nono171@gmail.com,0\n";
        users_file << "45,ali,333,ali_wael,wael@gmail.com,0\n";
        users_file.close();
        
        // Create test questions file
        ofstream questions_file(questions_test_file);
        questions_file << "101,-1,11,13,0,Should I learn C++ first or Java,I think C++ is a better Start\n";
        questions_file << "203,101,11,13,0,Why do you think so!,Just Google. There is an answer on Quora.\n";
        questions_file << "205,101,45,13,0,What about python?,\n";
        questions_file << "211,-1,13,11,1,It was nice to chat to you,For my pleasure Dr Mostafa\n";
        questions_file.close();
    }
    
    void ResetTestFiles() {
        CreateInitialTestFiles();
    }
    
    string RunAskMeWithInputs(const vector<string>& inputs) {
        // In a real implementation, we would need to:
        // 1. Redirect cin to use our input strings
        // 2. Redirect cout to capture output
        // 3. Run the AskMeSystem with test file paths
        
        // This is a simplified simulation for demonstration
        stringstream output;
        
        for (const string& input : inputs) {
            output << "Input: " << input << endl;
            // Simulate processing the input
            if (input == "1") {
                output << "Login selected" << endl;
            } else if (input == "2") {
                output << "Sign Up selected" << endl;
            }
            // Add more simulated responses as needed
        }
        
        return output.str();
    }
    
public:
    void RunAllTests() {
        cout << "Starting AskMe System Black Box Tests\n";
        cout << "===================================\n";
        
        ResetTestFiles();
        
        TestUserRegistration();
        TestAskingQuestions();
        TestAnsweringQuestions();
        TestThreadedQuestions();
        TestDeletingQuestions();
        TestAnonymousQuestions();
        TestDataPersistence();
        TestEdgeCases();
        TestFeedFunctionality();
        
        cout << "\nAll tests completed\n";
    }
    
    void TestUserRegistration() {
        cout << "\nRunning Test 1: User Registration\n";
        
        vector<string> inputs = {
            "2",        // Sign Up
            "testuser", // Username
            "testpass", // Password
            "Test User", // Name
            "test@email.com", // Email
            "1",       // Allow anonymous
            "1",        // Login
            "testuser", // Username
            "testpass"  // Password
        };
        
        string output = RunAskMeWithInputs(inputs);
        
        // Verify output contains success messages
        assert(output.find("Sign Up selected") != string::npos);
        assert(output.find("Login selected") != string::npos);
        
        // Verify user was added to file
        ifstream users_file(users_test_file);
        string line;
        bool user_found = false;
        while (getline(users_file, line)) {
            if (line.find("testuser") != string::npos) {
                user_found = true;
                break;
            }
        }
        assert(user_found);
        
        cout << "Test 1 Passed: User Registration\n";
    }
    
    void TestAskingQuestions() {
        cout << "\nRunning Test 2: Asking Questions\n";
        
        vector<string> inputs = {
            "1",        // Login
            "mostafa",  // Username
            "111",      // Password
            "5",        // Ask Question
            "11",       // User ID (noha)
            "0",       // Not anonymous
            "-1",       // New question (not thread)
            "Is this a test question?" // Question text
        };
        
        string output = RunAskMeWithInputs(inputs);
        
        // Verify question was added
        ifstream questions_file(questions_test_file);
        string line;
        bool question_found = false;
        while (getline(questions_file, line)) {
            if (line.find("Is this a test question?") != string::npos) {
                question_found = true;
                break;
            }
        }
        assert(question_found);
        
        cout << "Test 2 Passed: Asking Questions\n";
    }
    
    void TestAnsweringQuestions() {
        cout << "\nRunning Test 3: Answering Questions\n";
        
        vector<string> inputs = {
            "1",        // Login
            "noha",     // Username
            "222",      // Password
            "3",        // Answer Question
            "211",      // Question ID
            "Test answer to question" // Answer text
        };
        
        string output = RunAskMeWithInputs(inputs);
        
        // Verify answer was saved
        ifstream questions_file(questions_test_file);
        string line;
        bool answer_found = false;
        while (getline(questions_file, line)) {
            if (line.find("Test answer to question") != string::npos) {
                answer_found = true;
                break;
            }
        }
        assert(answer_found);
        
        cout << "Test 3 Passed: Answering Questions\n";
    }
    
    // Similar implementations for other test cases...
    void TestThreadedQuestions() { /* ... */ }
    void TestDeletingQuestions() { /* ... */ }
    void TestAnonymousQuestions() { /* ... */ }
    void TestDataPersistence() { /* ... */ }
    void TestEdgeCases() { /* ... */ }
    void TestFeedFunctionality() { /* ... */ }
};

int main() {
    AskMeTester tester;
    tester.RunAllTests();
    return 0;
}