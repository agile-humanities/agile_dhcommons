# Agile Humanities DHCommons Module

The Agile DHCommons Module works in conjunction with the Agile DiRT Module to allow meaningful exchange of information between the DHCommons and DiRT websites.

It is assumed that API-Key authentication will be used to restrict access to published data. If authentication is used, the Drupal Services API Key Authentication module must be installed and enabled. If access is to be left open, all further references to API keys may be ignored.

The DHCommons module is comprised of two parts&mdash;one to publish data associated with individual projects defined by the DHCommons ‘project' content type, and another to read and present published data defined by the DiRT ‘item’ content type.

## Preparation

Install and enable the Agile Humanities DHCommons Features Module. This indicates to the installer all required sub-modules and defines the necessary content types. This step may be omitted if your site is already configured with a standard DHCommons installation.

Install and enable the Agile Humanities DHCommons Module.

Create a Drupal role called **rest user**, and give members of that role access to all permissions listed under Services.

Create a user called **RestUser**.  This fictional user exists only for configuration purposes. Credentials are unimportant. Assign this new user the role of **rest user**.

## Configure publishing

The administrator of the site must set up a REST endpoint.

Navigate to **admin/structure/services** to add an endpoint.

Click on the **API Key Settings** tab, then select **rest user** as the user role.

Click List, then **+Add** to navigate to **admin/structure/services/add**

Enter a machine-readable name for the endpoint, select **REST** as the server, and enter a path. The names chosen for the endpoint and path are not significant. Use **rest** for both the machine-readable name and the path of the endpoint.

Check **API Key Authentication**. The other boxes should remain unchecked.

**_Save!_**

Edit the rest endpoint by clicking **Edit Resources**. In the **Server** tab, check **all** boxes.

**_Save!_**

Under **Authentication**, select **RestUser** as your user, and enter an API key. This key can be anything; in our test example, use **agile_key**.

**_Save!_**

Under **Resources** check **item**. Enter**project** in the alias textfield opposite **item**.

Test the endpoint by entering `<your site name>/rest`

You should see a message indication the endpoint has been properly set up.

Test authentication by entering `<your site name>/rest/project/fetch`

You should be asked for a password. Clicking cancel should give an **Unauthorized** access message.

If you’ve created a few full populated item nodes, the following should bring back sample data:

`<your site name>/rest/project/fetch?api-key=agile_key`

Your site is now ready to publish via REST to a properly configured subscriber site.

To configure the connection, your subscriber site must know your site’s API-key, site url, REST path, alias, and taxonomy.

## Configure subscribing

Navigate to **admin/config/services/dirt**

The Agile DiRT Module has a similar configuration to the Agile DHCommons Module. From the DHCommons administrator, you will require the API key, tool site url, REST path, and alias. Enter these values and your site should be able to retrieve item information from DiRT.

The connection can be tested by entering `<dirt url>/<rest path>/<alias>/fetch?api-key=<supplied key>`
