/** \file application.h
 *  \brief Application header
 */

#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <memory>
#include <vector>
#include "basic.h"
#include "customer.h"
#include "enterprise.h"
#include "id_generator.h"

class Application {
public:
    /**
     * Application constructor
     */
    Application();

    /**
     * Application destructor
     */
    virtual ~Application();

    /**
     * Run the application
     */
    void run();
private:
    std::vector<std::shared_ptr<Basic>> accounts;   //<! All accounts

    /**
     * Get account details. This will print out account details if the account is exist.
     * \param query name of company or name of individual
     */
    void getAccountDetails(std::string query);

    /**
     * Create account helper function.
     */
    void createAccount();

    /**
     * Deposit to account helper function.
     */
    void deposit();

    /**
     * Withdraw from account helper function.
     */
    void withdraw();

    /**
     * Query account details helper function.
     */
    void query();
};


#endif /* define __APPLICATION_H__ */