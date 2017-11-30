# Contributing to ```ctp7_modules```
The following are a set of guidelines to help you in contributing to the ```ctp7_modules``` code base.

## How to start developing
Start by forking the central [```ctp7_modules```](https://github.com/cms-gem-daq-project/ctp7_modules) repository.
Once you have your fork, then you can check it out to wherever you will be developing.


### Workflow
We have been utilizing a very helpful guideline for our development model outlined here: [```git-flow```](http://nvie.com/posts/a-successful-git-branching-model/)
The basic idea is the following:
* fork from [cms-gem-daq-project/ctp7_modules](https://github.com/cms-gem-daq-project/ctp7_modules)
* create a branch to develop your particular feature (based off of ```develop```, or in some cases, the current ```release``` branch)
  * ```hotfix``` may be created from ```master```
  * once that feature is completed, create a pull request
* ```master``` should *always* be stable
  * Do *not* commit directly onto ```master``` or ```develop```, and ensure that your ```master``` and ```develop``` are up-to-date with ```cms-gem-daq-project``` before starting new developments

* Some generally good guidelines(though this post recommends *not* using the ```git-flow``` model[](https://juliansimioni.com/blog/three-git-commands-you-should-never-use/)
  * *Never* use ```git commit -a```
  * *Avoid* ```git commit -m``` over ```git commit -p``` or ```git commit```, as it will force you to think about your commit message
    * Speaking of... commit messages should be descriptive, not like a novel, but concise and complete.  If they reference an issue or PR, please include that information.
  * *Prefer* ```git rebase``` over ```git pull```

### Coding Style
* Avoid using ```tab```s, use an editor that is smart enough to convert all ```tab```s to ```space```s
* Current convention is 4 ```space```s per ```tab``` for ```python``` and ```c++``` code

### Testing
To be filled in
* Some automatic tests are being set up to use some continuous integration tests

## Making a pull request
Once you have tested your code, you are ready to make a pull request.  If it references an issue or another pull request, make sure to include that information.

### Using Labels
#### Issue and Pull Request Labels
There are several labels used to track issues.  Unfortunately, due to the way that github is set up, general users are not
able to add these labels.  As such, they are outlined here, and when creating an issue or pull request, should be referenced
in the title so that the maintainers can apply the appropriate label easily.

| Label name | `cms-gem-daq-project/ctp7_modules` :mag_right: | `cms-gem-daq-project` :mag_right: | Description |
| ---------- |:------------------------------------------ |:--------------------------------- |:----------- |
| `Type: Bug` | search [`ctp7_modules`][search-ctp7_modules-repo-label-bug] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-bug] for issues | Issue reports a `bug`, and supplementary information, i.e., how to reproduce, useful debugging info, etc. |
| `Type: Bugfix` | search [`ctp7_modules`][search-ctp7_modules-repo-label-bugfix] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-bugfix] for issues | Issue reports a `bugfix`, and references the bug issue |
| `Type: Duplicate` | search [`ctp7_modules`][search-ctp7_modules-repo-label-duplicate] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-duplicate] for issues | Issue will be tagged as `duplicate`, and a reference to the initial issue will be added|
| `Type: Enhancement` | search [`ctp7_modules`][search-ctp7_modules-repo-label-enhancement] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-enhancement] for issues | Issue reports an `enhancement` |
| `Type: Feature Request` | search [`ctp7_modules`][search-ctp7_modules-repo-label-feature-request] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-feature-request] for issues | Issue contains a `feature-request` |
| `Type: Maintenance` | search [`ctp7_modules`][search-ctp7_modules-repo-label-maintenance] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-maintenance] for issues | Issue reports a `maintenance` or `maintenance` request |
| `Type: New Tag` | search [`ctp7_modules`][search-ctp7_modules-repo-label-new-tag] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-new-tag] for issues | Issue reports a bug, and supplementary information, i.e., how to reproduce, useful debugging info, etc. |
| `Type: Question` | search [`ctp7_modules`][search-ctp7_modules-repo-label-question] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-question] for issues | Issue raises a question, though it will generally be better to contact on mattermost |
| `Type: Answer` | search [`ctp7_modules`][search-ctp7_modules-repo-label-answer] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-label-answer] for issues | Issue will answer a previously referenced question|

#### Issue and Pull Request Labels
Maintainers will (hopefully) attach a priority based on the information given in the issue/PR.

| Label name | `cms-gem-daq-project/ctp7_modules` :mag_right: | `cms-gem-daq-project` :mag_right: | Description |
| ---------- |:------------------------------------------ |:--------------------------------- |:----------- |
| `Priority: Low` | search [`ctp7_modules`][search-ctp7_modules-repo-priority-low] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-priority-low] for issues | Priority `low` assigned to issue/PR |
| `Priority: Medium` | search [`ctp7_modules`][search-ctp7_modules-repo-priority-medium] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-priority-medium] for issues | Priority `medium` assigned to issue/PR |
| `Priority: High` | search [`ctp7_modules`][search-ctp7_modules-repo-priority-high] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-priority-high] for issues | Priority `high` assigned to issue/PR |
| `Priority: Critical` | search [`ctp7_modules`][search-ctp7_modules-repo-priority-critical] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-priority-critical] for issues | Priority `critical` assigned to issue/PR |

#### Pull Request Status Labels
Maintainers will (hopefully) properly migrate issues and pull requests through the various stages on their path to resolution.

| Label name | `cms-gem-daq-project/ctp7_modules` :mag_right: | `cms-gem-daq-project` :mag_right: | Description |
| ---------- |:------------------------------------------ |:--------------------------------- |:----------- |
| `Status: Blocked` | search [`ctp7_modules`][search-ctp7_modules-repo-status-blocked] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-blocked] for issues | Issue/PR `blocked`: depends on some other issue/PR (should be referenced) |
| `Status: Pending` | search [`ctp7_modules`][search-ctp7_modules-repo-status-pending] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-pending] for issues | Issue/PR `pending`: acknowledged, ready to be reviewed |
| `Status: Accepted` | search [`ctp7_modules`][search-ctp7_modules-repo-status-accepted] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-accepted] for issues | Issue/PR `accepted`: accepted |
| `Status: Completed` | search [`ctp7_modules`][search-ctp7_modules-repo-status-completed] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-completed] for issues | Issue/PR `completed`: ready for inclusion |
| `Status: Invalid` | search [`ctp7_modules`][search-ctp7_modules-repo-status-invalid] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-invalid] for issues | Issue/PR `invalid`: invalid, possibly can't reproduce |
| `Status: Wontfix` | search [`ctp7_modules`][search-ctp7_modules-repo-status-wontfix] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-wontfix] for issues | Issue/PR `wontfix`: won't be included as-is |
| `Status: Wrong Repo` | search [`ctp7_modules`][search-ctp7_modules-repo-status-wrong-repo] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-wrong-repo] for issues | Issue/PR `wrong-repo`: issue reported in incorrect repository |
| `Status: Help Wanted` | search [`ctp7_modules`][search-ctp7_modules-repo-status-help-wanted] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-help-wanted] for issues | Issue/PR `help-wanted`: call for someone to take on the task |
| `Status: Revision Needed` | search [`ctp7_modules`][search-ctp7_modules-repo-status-revision-needed] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-revision-needed] for issues | Issue/PR `revision-needed`: something needs to be changed before proceeding |
| `Status: On Hold` | search [`ctp7_modules`][search-ctp7_modules-repo-status-on-hold] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-on-hold] for issues | Issue/PR `on-hold`:  being worked on, but either stale, or waiting for inputs |
| `Status: In Progress` | search [`ctp7_modules`][search-ctp7_modules-repo-status-in-progress] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-in-progress] for issues | Issue/PR `in-progress`:  actively being worked on |
| `Status: Review Needed` | search [`ctp7_modules`][search-ctp7_modules-repo-status-review-needed] for issues | search [`cms-gem-daq-project`][search-cms-gem-daq-project-status-review-needed] for issues | Issue/PR `review-needed`: ready for inclusion, needs review |

###### Acknowledgements
* Much style and syntax of this was borrowed heavily from the [atom](https://github.com/atom/atom/blob/master/CONTRIBUTING.md) repository

[search-ctp7_modules-repo-label-bug]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Bug%22
[search-cms-gem-daq-project-label-bug]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Bug%22
[search-ctp7_modules-repo-label-bugfix]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Bugfix%22
[search-cms-gem-daq-project-label-bugfix]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Bugfix%22
[search-ctp7_modules-repo-label-duplicate]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Duplicate%22
[search-cms-gem-daq-project-label-duplicate]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Duplicate%22
[search-ctp7_modules-repo-label-enhancement]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Enhancement%22
[search-cms-gem-daq-project-label-enhancement]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Enhancement%22
[search-ctp7_modules-repo-label-feature-request]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Feature+Request%22
[search-cms-gem-daq-project-label-feature-request]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Feature+Request%22
[search-ctp7_modules-repo-label-maintenance]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Maintenance%22
[search-cms-gem-daq-project-label-maintenance]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Maintenance%22
[search-ctp7_modules-repo-label-question]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Question%22
[search-cms-gem-daq-project-label-question]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Question%22
[search-ctp7_modules-repo-label-answer]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+Answer%22
[search-cms-gem-daq-project-label-answer]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+Answer%22
[search-ctp7_modules-repo-label-new-tag]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Type%3A+New+Tag%22
[search-cms-gem-daq-project-label-new-tag]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Type%3A+New+Tag%22

[search-ctp7_modules-repo-priority-low]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Priority%3A+Low%22
[search-cms-gem-daq-project-priority-low]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Priority%3A+Low%22
[search-ctp7_modules-repo-priority-medium]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Priority%3A+Medium%22
[search-cms-gem-daq-project-priority-medium]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Priority%3A+Medium%22
[search-ctp7_modules-repo-priority-high]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Priority%3A+High%22
[search-cms-gem-daq-project-priority-high]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Priority%3A+High%22
[search-ctp7_modules-repo-priority-critical]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Priority%3A+Critical%22
[search-cms-gem-daq-project-priority-critical]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Priority%3A+Critical%22

[search-ctp7_modules-repo-status-invalid]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Invalid%22
[search-cms-gem-daq-project-status-invalid]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Invalid%22
[search-ctp7_modules-repo-status-wontfix]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Wontfix%22
[search-cms-gem-daq-project-status-wontfix]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Wontfix%22
[search-ctp7_modules-repo-status-accepted]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Accepted%22
[search-cms-gem-daq-project-status-accepted]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Accepted%22
[search-ctp7_modules-repo-status-completed]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Completed%22
[search-cms-gem-daq-project-status-completed]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Completed%22
[search-ctp7_modules-repo-status-pending]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Pending%22
[search-cms-gem-daq-project-status-pending]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Pending%22
[search-ctp7_modules-repo-status-blocked]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Blocked%22
[search-cms-gem-daq-project-status-blocked]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Blocked%22
[search-ctp7_modules-repo-status-wrong-repo]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Wrong+Repo%22
[search-cms-gem-daq-project-status-wrong-repo]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Wrong+Repo%22
[search-ctp7_modules-repo-status-help-wanted]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Help+Wanted%22
[search-cms-gem-daq-project-status-help-wanted]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Help+Wanted%22
[search-ctp7_modules-repo-status-revision-needed]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Revision+Needed%22
[search-cms-gem-daq-project-status-revision-needed]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Revision+Needed%22
[search-ctp7_modules-repo-status-review-needed]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+Review+Needed%22
[search-cms-gem-daq-project-status-review-needed]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+Review+Needed%22
[search-ctp7_modules-repo-status-on-hold]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+On+Hold%22
[search-cms-gem-daq-project-status-on-hold]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+On+Hold%22
[search-ctp7_modules-repo-status-in-progress]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+repo%3Actp7_modules+user%3Acms-gem-daq-project+label%3A%22Status%3A+In+Progress%22
[search-cms-gem-daq-project-status-in-progress]: https://github.com/issues?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+user%3Acms-gem-daq-project+label%3A%22Status%3A+In+Progress%22
