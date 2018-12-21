# [“Cannot Open DDE Link to”: Problems with Adobe Acrobat Pro DC 2017 and WinEdt](https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt)

[Ask Question](https://tex.stackexchange.com/questions/ask)

原文链接：<https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt>

While using the 2017 release of Adobe Acrobat DC, I get the error

[![error WinEdt Adobe Acrobat DC 2017](https://i.stack.imgur.com/11MM1.png)](https://i.stack.imgur.com/11MM1.png)

every time I run PDFLatex with my PDF open. When I use PDF Search, I get the same error.

Does anybody know what do I have to change in the `.edt` files to make it work?

[errors](https://tex.stackexchange.com/questions/tagged/errors) [viewers](https://tex.stackexchange.com/questions/tagged/viewers) [winedt](https://tex.stackexchange.com/questions/tagged/winedt) [adobe](https://tex.stackexchange.com/questions/tagged/adobe)

[share](https://tex.stackexchange.com/q/365939)[improve this question](https://tex.stackexchange.com/posts/365939/edit)

[edited Nov 20 '17 at 6:32](https://tex.stackexchange.com/posts/365939/revisions)

![img](https://i.stack.imgur.com/rWvYi.gif?s=32&g=1)

karlkoeller

105k9189350

asked Apr 21 '17 at 16:16

![img](https://www.gravatar.com/avatar/445098003ce085de027744cca1c4f815?s=32&d=identicon&r=PG&f=1)

Paco Vazquez-Grande

3314

- 2

  Update your winedt. Alex said he has changed the macros. Alternatively you would need to change adobe.edt to set the service to acroviewA17 (or acroviewR17). – [Ulrike Fischer](https://tex.stackexchange.com/users/2388/ulrike-fischer) [Apr 21 '17 at 21:08](https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt#comment901945_365939)

- 

  Welcome to TeX.SX! You can have a look at [our starter guide](https://meta.tex.stackexchange.com/q/1436) to familiarize yourself further with our format. – [Martin Schröder](https://tex.stackexchange.com/users/5763/martin-schr%c3%b6der) [Apr 22 '17 at 12:52](https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt#comment902108_365939)

add a comment



## 1 Answer

[active](https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt?answertab=active#tab-top)[oldest](https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt?answertab=oldest#tab-top)[votes](https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt?answertab=votes#tab-top)



up vote8down voteaccepted

Support for Adobe Acrobat DC 2017 has been added only in WinEdt 10.2 Build 20170413.

The name of the DDE service is, in the case of Acrobat DC Pro 2017, `AcroviewA17`, while in the case of Adobe Reader DC 2017, `AcroviewR17`.

You have to insert this value in the Options menu -> Execution Modes dialog -> PDF Viewer tab -> Adobe DDE Service Blues field and the then press OK, as in the image below.

[![enter image description here](https://i.stack.imgur.com/iEAyZ.png)](https://i.stack.imgur.com/iEAyZ.png)

Notice that it might not work if you have a local copy of `Adobe.edt` in the path `C:\Users\<user>\AppData\Roaming\WinEdt Team\WinEdt 10\Config`. In this case, simply delete that file and restart WinEdt.

------

If you can't upgrade to the latest version of WinEdt, you can instead open a local copy of the file `Adobe.edt` from the Options menu -> Options Interface dialog -> Advanced Configuration -> PDF Macros -> Adobe Blues.

[![enter image description here](https://i.stack.imgur.com/ABSFC.png)](https://i.stack.imgur.com/ABSFC.png)

In this file, replace the line at the very end of it

```tex
// Assign(!"Acro-DDE_Service",!"AcroviewR11");
```

with the following

```tex
Assign(!"Acro-DDE_Service",!"AcroviewA17");
```

then save the file and restart WinEdt.

------

## Addendum: Name of the DDE service for different versions of Adobe DC

- **Adobe Reader DC 2015**: `AcroviewR15`
- **Acrobat DC Pro 2015**: `AcroviewA15`
- **Adobe Reader DC 2017**: `AcroviewR17`
- **Acrobat DC Pro 2017**: `AcroviewA17`
- **Adobe Reader DC 2018**: `AcroviewR18`
- **Acrobat DC Pro 2018**: `AcroviewA18`

Unless Adobe changes its naming convention, for future versions it suffices to change the last two digits according to the year version.

[share](https://tex.stackexchange.com/a/366103)[improve this answer](https://tex.stackexchange.com/posts/366103/edit)

[edited Nov 20 '17 at 6:27](https://tex.stackexchange.com/posts/366103/revisions)





answered Apr 22 '17 at 17:49

![img](https://i.stack.imgur.com/rWvYi.gif?s=32&g=1)

karlkoeller

105k9189350

- 

  Thank you very much! installing WinEdt 10 solves the problem. Thank you! Francisco – [Paco Vazquez-Grande](https://tex.stackexchange.com/users/131835/paco-vazquez-grande) [Apr 24 '17 at 13:50](https://tex.stackexchange.com/questions/365939/cannot-open-dde-link-to-problems-with-adobe-acrobat-pro-dc-2017-and-winedt#comment903255_366103)

add a comment