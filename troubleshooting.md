# Issues and Solutions

## Can't login vscode-leetcode

* Spent an hour and figured it out. Here are the step by step instructions by people newbie like me.

* Make sure Node.js 8+ is installed. Instructions can be found on the official page

* Install leetcode-cli from OS terminal or the terminal within vscode. Installation guide. Note the "From Github" section links to an older version.

  ```javascript
  # to remove the old version
  npm uninstall -g leetcode-cli
  # to install the up-to-date version(2.6.17+)
  npm install -g leetcode-tools/leetcode-cli
  ```

* Type leetcode version in terminal to make sure you installed version 2.6.17+.

* Log into leetcode.com in a browser. In Chrome, right click and select "Inspect". Switch to tab "Network", "XHR". Then click any button on leetcode.com(now should be on the left split screen). Now you should be able to see the cookie as @yihong0618 showed in the pic. Copy the entire cookie string starting from "__cfduid" and ending with "_gat=1"

* Type leetcode user -c from terminal within vscode. Follow the prompt and type in your username and cookie you copied above.
