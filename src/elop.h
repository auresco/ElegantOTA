#ifndef elop_h
#define elop_h

#include <Arduino.h>

const char ELEGANT_HTML[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang='en' class='dark'>
    <head>
        <meta charset='UTF-8'/>
        <meta name='viewport' content='width=device-width, initial-scale=1.0'/>
        <link rel='icon' href='data:image/png;base64,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' type='image/png'>
        <title>EnergySpot Update</title>
        <script type='module' crossorigin>
            (function() {
                const f = document.createElement('link').relList;
                if (f && f.supports && f.supports('modulepreload'))
                    return;
                for (const a of document.querySelectorAll('link[rel=\'modulepreload\']'))
                    d(a);
                new MutationObserver(a => {
                    for (const c of a)
                        if (c.type === 'childList')
                            for (const i of c.addedNodes)
                                i.tagName === 'LINK' && i.rel === 'modulepreload' && d(i)
                }
                ).observe(document, {
                    childList: !0,
                    subtree: !0
                });
                function s(a) {
                    const c = {};
                    return a.integrity && (c.integrity = a.integrity),
                    a.referrerPolicy && (c.referrerPolicy = a.referrerPolicy),
                    a.crossOrigin === 'use-credentials' ? c.credentials = 'include' : a.crossOrigin === 'anonymous' ? c.credentials = 'omit' : c.credentials = 'same-origin',
                    c
                }
                function d(a) {
                    if (a.ep)
                        return;
                    a.ep = !0;
                    const c = s(a);
                    fetch(a.href, c)
                }
            }
            )();
            function A(l) {
                return l && l.__esModule && Object.prototype.hasOwnProperty.call(l, 'default') ? l.default : l
            }
            var L = {
                exports: {}
            }
              , x = {
                exports: {}
            };
            (function() {
                var l = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
                  , f = {
                    rotl: function(s, d) {
                        return s << d | s >>> 32 - d
                    },
                    rotr: function(s, d) {
                        return s << 32 - d | s >>> d
                    },
                    endian: function(s) {
                        if (s.constructor == Number)
                            return f.rotl(s, 8) & 16711935 | f.rotl(s, 24) & 4278255360;
                        for (var d = 0; d < s.length; d++)
                            s[d] = f.endian(s[d]);
                        return s
                    },
                    randomBytes: function(s) {
                        for (var d = []; s > 0; s--)
                            d.push(Math.floor(Math.random() * 256));
                        return d
                    },
                    bytesToWords: function(s) {
                        for (var d = [], a = 0, c = 0; a < s.length; a++,
                        c += 8)
                            d[c >>> 5] |= s[a] << 24 - c % 32;
                        return d
                    },
                    wordsToBytes: function(s) {
                        for (var d = [], a = 0; a < s.length * 32; a += 8)
                            d.push(s[a >>> 5] >>> 24 - a % 32 & 255);
                        return d
                    },
                    bytesToHex: function(s) {
                        for (var d = [], a = 0; a < s.length; a++)
                            d.push((s[a] >>> 4).toString(16)),
                            d.push((s[a] & 15).toString(16));
                        return d.join('')
                    },
                    hexToBytes: function(s) {
                        for (var d = [], a = 0; a < s.length; a += 2)
                            d.push(parseInt(s.substr(a, 2), 16));
                        return d
                    },
                    bytesToBase64: function(s) {
                        for (var d = [], a = 0; a < s.length; a += 3)
                            for (var c = s[a] << 16 | s[a + 1] << 8 | s[a + 2], i = 0; i < 4; i++)
                                a * 8 + i * 6 <= s.length * 8 ? d.push(l.charAt(c >>> 6 * (3 - i) & 63)) : d.push('=');
                        return d.join('')
                    },
                    base64ToBytes: function(s) {
                        s = s.replace(/[^A-Z0-9+\/]/ig, '');
                        for (var d = [], a = 0, c = 0; a < s.length; c = ++a % 4)
                            c != 0 && d.push((l.indexOf(s.charAt(a - 1)) & Math.pow(2, -2 * c + 8) - 1) << c * 2 | l.indexOf(s.charAt(a)) >>> 6 - c * 2);
                        return d
                    }
                };
                x.exports = f
            }
            )();
            var H = x.exports
              , F = {
                utf8: {
                    stringToBytes: function(l) {
                        return F.bin.stringToBytes(unescape(encodeURIComponent(l)))
                    },
                    bytesToString: function(l) {
                        return decodeURIComponent(escape(F.bin.bytesToString(l)))
                    }
                },
                bin: {
                    stringToBytes: function(l) {
                        for (var f = [], s = 0; s < l.length; s++)
                            f.push(l.charCodeAt(s) & 255);
                        return f
                    },
                    bytesToString: function(l) {
                        for (var f = [], s = 0; s < l.length; s++)
                            f.push(String.fromCharCode(l[s]));
                        return f.join('')
                    }
                }
            }
              , I = F;
            var O = function(l) {
                return l != null && (M(l) || P(l) || !!l._isBuffer)
            };
            function M(l) {
                return !!l.constructor && typeof l.constructor.isBuffer == 'function' && l.constructor.isBuffer(l)
            }
            function P(l) {
                return typeof l.readFloatLE == 'function' && typeof l.slice == 'function' && M(l.slice(0, 0))
            }
            (function() {
                var l = H
                  , f = I.utf8
                  , s = O
                  , d = I.bin
                  , a = function(c, i) {
                    c.constructor == String ? i && i.encoding === 'binary' ? c = d.stringToBytes(c) : c = f.stringToBytes(c) : s(c) ? c = Array.prototype.slice.call(c, 0) : !Array.isArray(c) && c.constructor !== Uint8Array && (c = c.toString());
                    for (var r = l.bytesToWords(c), p = c.length * 8, n = 1732584193, e = -271733879, o = -1732584194, t = 271733878, u = 0; u < r.length; u++)
                        r[u] = (r[u] << 8 | r[u] >>> 24) & 16711935 | (r[u] << 24 | r[u] >>> 8) & 4278255360;
                    r[p >>> 5] |= 128 << p % 32,
                    r[(p + 64 >>> 9 << 4) + 14] = p;
                    for (var m = a._ff, g = a._gg, h = a._hh, y = a._ii, u = 0; u < r.length; u += 16) {
                        var C = n
                          , S = e
                          , k = o
                          , _ = t;
                        n = m(n, e, o, t, r[u + 0], 7, -680876936),
                        t = m(t, n, e, o, r[u + 1], 12, -389564586),
                        o = m(o, t, n, e, r[u + 2], 17, 606105819),
                        e = m(e, o, t, n, r[u + 3], 22, -1044525330),
                        n = m(n, e, o, t, r[u + 4], 7, -176418897),
                        t = m(t, n, e, o, r[u + 5], 12, 1200080426),
                        o = m(o, t, n, e, r[u + 6], 17, -1473231341),
                        e = m(e, o, t, n, r[u + 7], 22, -45705983),
                        n = m(n, e, o, t, r[u + 8], 7, 1770035416),
                        t = m(t, n, e, o, r[u + 9], 12, -1958414417),
                        o = m(o, t, n, e, r[u + 10], 17, -42063),
                        e = m(e, o, t, n, r[u + 11], 22, -1990404162),
                        n = m(n, e, o, t, r[u + 12], 7, 1804603682),
                        t = m(t, n, e, o, r[u + 13], 12, -40341101),
                        o = m(o, t, n, e, r[u + 14], 17, -1502002290),
                        e = m(e, o, t, n, r[u + 15], 22, 1236535329),
                        n = g(n, e, o, t, r[u + 1], 5, -165796510),
                        t = g(t, n, e, o, r[u + 6], 9, -1069501632),
                        o = g(o, t, n, e, r[u + 11], 14, 643717713),
                        e = g(e, o, t, n, r[u + 0], 20, -373897302),
                        n = g(n, e, o, t, r[u + 5], 5, -701558691),
                        t = g(t, n, e, o, r[u + 10], 9, 38016083),
                        o = g(o, t, n, e, r[u + 15], 14, -660478335),
                        e = g(e, o, t, n, r[u + 4], 20, -405537848),
                        n = g(n, e, o, t, r[u + 9], 5, 568446438),
                        t = g(t, n, e, o, r[u + 14], 9, -1019803690),
                        o = g(o, t, n, e, r[u + 3], 14, -187363961),
                        e = g(e, o, t, n, r[u + 8], 20, 1163531501),
                        n = g(n, e, o, t, r[u + 13], 5, -1444681467),
                        t = g(t, n, e, o, r[u + 2], 9, -51403784),
                        o = g(o, t, n, e, r[u + 7], 14, 1735328473),
                        e = g(e, o, t, n, r[u + 12], 20, -1926607734),
                        n = h(n, e, o, t, r[u + 5], 4, -378558),
                        t = h(t, n, e, o, r[u + 8], 11, -2022574463),
                        o = h(o, t, n, e, r[u + 11], 16, 1839030562),
                        e = h(e, o, t, n, r[u + 14], 23, -35309556),
                        n = h(n, e, o, t, r[u + 1], 4, -1530992060),
                        t = h(t, n, e, o, r[u + 4], 11, 1272893353),
                        o = h(o, t, n, e, r[u + 7], 16, -155497632),
                        e = h(e, o, t, n, r[u + 10], 23, -1094730640),
                        n = h(n, e, o, t, r[u + 13], 4, 681279174),
                        t = h(t, n, e, o, r[u + 0], 11, -358537222),
                        o = h(o, t, n, e, r[u + 3], 16, -722521979),
                        e = h(e, o, t, n, r[u + 6], 23, 76029189),
                        n = h(n, e, o, t, r[u + 9], 4, -640364487),
                        t = h(t, n, e, o, r[u + 12], 11, -421815835),
                        o = h(o, t, n, e, r[u + 15], 16, 530742520),
                        e = h(e, o, t, n, r[u + 2], 23, -995338651),
                        n = y(n, e, o, t, r[u + 0], 6, -198630844),
                        t = y(t, n, e, o, r[u + 7], 10, 1126891415),
                        o = y(o, t, n, e, r[u + 14], 15, -1416354905),
                        e = y(e, o, t, n, r[u + 5], 21, -57434055),
                        n = y(n, e, o, t, r[u + 12], 6, 1700485571),
                        t = y(t, n, e, o, r[u + 3], 10, -1894986606),
                        o = y(o, t, n, e, r[u + 10], 15, -1051523),
                        e = y(e, o, t, n, r[u + 1], 21, -2054922799),
                        n = y(n, e, o, t, r[u + 8], 6, 1873313359),
                        t = y(t, n, e, o, r[u + 15], 10, -30611744),
                        o = y(o, t, n, e, r[u + 6], 15, -1560198380),
                        e = y(e, o, t, n, r[u + 13], 21, 1309151649),
                        n = y(n, e, o, t, r[u + 4], 6, -145523070),
                        t = y(t, n, e, o, r[u + 11], 10, -1120210379),
                        o = y(o, t, n, e, r[u + 2], 15, 718787259),
                        e = y(e, o, t, n, r[u + 9], 21, -343485551),
                        n = n + C >>> 0,
                        e = e + S >>> 0,
                        o = o + k >>> 0,
                        t = t + _ >>> 0
                    }
                    return l.endian([n, e, o, t])
                };
                a._ff = function(c, i, r, p, n, e, o) {
                    var t = c + (i & r | ~i & p) + (n >>> 0) + o;
                    return (t << e | t >>> 32 - e) + i
                }
                ,
                a._gg = function(c, i, r, p, n, e, o) {
                    var t = c + (i & p | r & ~p) + (n >>> 0) + o;
                    return (t << e | t >>> 32 - e) + i
                }
                ,
                a._hh = function(c, i, r, p, n, e, o) {
                    var t = c + (i ^ r ^ p) + (n >>> 0) + o;
                    return (t << e | t >>> 32 - e) + i
                }
                ,
                a._ii = function(c, i, r, p, n, e, o) {
                    var t = c + (r ^ (i | ~p)) + (n >>> 0) + o;
                    return (t << e | t >>> 32 - e) + i
                }
                ,
                a._blocksize = 16,
                a._digestsize = 16,
                L.exports = function(c, i) {
                    if (c == null)
                        throw new Error('Illegal argument ' + c);
                    var r = l.wordsToBytes(a(c, i));
                    return i && i.asBytes ? r : i && i.asString ? d.bytesToString(r) : l.bytesToHex(r)
                }
            }
            )();
            var U = L.exports;
            const R = A(U)
              , v = l => {
                document.getElementById(l).classList.remove('hidden')
            }
              , B = l => {
                document.getElementById(l).classList.add('hidden')
            }
              , w = l => {
                document.getElementById('progressTitle').innerHTML = l
            }
              , E = l => {
                document.getElementById('errorTitle').innerHTML = l
            }
              , T = l => {
                document.getElementById('errorReason').innerHTML = l
            }
              , D = async l => new Promise( (f, s) => {
                let d = ''
                  , a = new FileReader;
                a.onload = function(c) {
                    d = R(c.target.result),
                    f(d)
                }
                ,
                a.readAsArrayBuffer(l)
            }
            )
              , N = async l => {
                B('uploadColumn'),
                //B('settingsColumn'),
                v('progressColumn');
                //let f = document.getElementById('otaMode').value;
                let element = document.getElementById("otaMode");
                let f = element ? element.value : "fr";
                try {
                    let s = await D(l);
                    w('Starting OTA Process');
                    const d = await fetch(`/ota/start?mode=${f}&hash=${s}`);
                    if (!d.ok)
                        throw new Error('Start OTA process failed');
                    const a = await d.text();
                    console.log('Start OTA response:', a);
                    const c = new FormData;
                    let i = new XMLHttpRequest;
                    i.open('POST', '/ota/upload'),
                    i.upload.addEventListener('progress', function(r) {
                        let p = Math.round(r.loaded / r.total * 100);
                        document.getElementById('progressBar').style.width = p + '%',
                        document.getElementById('progressValue').innerHTML = p + '%'
                    }, !1),
                    i.upload.onprogress = function(r) {
                        if (r.lengthComputable) {
                            let p = Math.round(r.loaded / r.total * 100);
                            document.getElementById('progressBar').style.width = p + '%',
                            document.getElementById('progressValue').innerHTML = p + '%'
                        }
                    }
                    ,
                    i.onreadystatechange = function() {
                        if (i.readyState == 4)
                            if (i.status == 200)
                                document.getElementById('progressBar').style.width = '100%',
                                document.getElementById('progressBar').innerHTML = '100%',
                                B('progressColumn'),
                                v('successColumn');
                            else if (i.status == 400) {
                                document.getElementById('progressBar').style.width = '100%',
                                document.getElementById('progressBar').innerHTML = '100%',
                                B('progressColumn'),
                                v('errorColumn'),
                                E('Upload failed');
                                let r = i.responseText;
                                T(r)
                            } else
                                document.getElementById('progressBar').style.width = '100%',
                                document.getElementById('progressBar').innerHTML = '100%',
                                B('progressColumn'),
                                v('errorColumn'),
                                E('Upload failed'),
                                T('Server returned status code ' + i.status)
                    }
                    ,
                    c.append('file', l, l.name),
                    i.send(c),
                    w('Uploading ' + l.name)
                } catch (s) {
                    B('progressColumn'),
                    v('errorColumn'),
                    E('Upload failed'),
                    T(s.message)
                }
            }
              , V = l => l.length > 1 && !multiple ? (alert('You can only upload one (.bin) file at a time.'),
            !1) : l[0].name.split('.').pop() != 'bin' ? (alert('You can only upload (.bin) files.'),
            !1) : !0;
            var q = document.getElementById('uploadButton')
              , $ = document.getElementById('fileInput');
            q.addEventListener('click', function(l) {
                l.preventDefault(),
                $.click()
            });
            function z(l) {
                if (!V(l))
                    return !1;
                N(l[0])
            }
            function G() {
                window.location.reload()
            }
            window.onFileInput = z;
            window.resetView = G;
        </script>
        <style>
            *,:before,:after {
                box-sizing: border-box;
                border-width: 0;
                border-style: solid;
                border-color: #e5e7eb
            }

            :before,:after {
                --tw-content: ''
            }

            html {
                line-height: 1.5;
                -webkit-text-size-adjust: 100%;
                -moz-tab-size: 4;
                -o-tab-size: 4;
                tab-size: 4;
                font-family: ui-sans-serif,system-ui,-apple-system,BlinkMacSystemFont,Segoe UI,Roboto,Helvetica Neue,Arial,Noto Sans,sans-serif,'Apple Color Emoji','Segoe UI Emoji',Segoe UI Symbol,'Noto Color Emoji';
                font-feature-settings: normal;
                font-variation-settings: normal
            }

            body {
                margin: 0;
                line-height: inherit
            }

            hr {
                height: 0;
                color: inherit;
                border-top-width: 1px
            }

            abbr:where([title]) {
                -webkit-text-decoration: underline dotted;
                text-decoration: underline dotted
            }

            h1,h2,h3,h4,h5,h6 {
                font-size: inherit;
                font-weight: inherit
            }

            a {
                color: inherit;
                text-decoration: inherit
            }

            b,strong {
                font-weight: bolder
            }

            code,kbd,samp,pre {
                font-family: ui-monospace,SFMono-Regular,Menlo,Monaco,Consolas,Liberation Mono,Courier New,monospace;
                font-size: 1em
            }

            small {
                font-size: 80%
            }

            sub,sup {
                font-size: 75%;
                line-height: 0;
                position: relative;
                vertical-align: baseline
            }

            sub {
                bottom: -.25em
            }

            sup {
                top: -.5em
            }

            table {
                text-indent: 0;
                border-color: inherit;
                border-collapse: collapse
            }

            button,input,optgroup,select,textarea {
                font-family: inherit;
                font-feature-settings: inherit;
                font-variation-settings: inherit;
                font-size: 100%;
                font-weight: inherit;
                line-height: inherit;
                color: inherit;
                margin: 0;
                padding: 0
            }

            button,select {
                text-transform: none
            }

            button,[type=button],[type=reset],[type=submit] {
                -webkit-appearance: button;
                background-color: transparent;
                background-image: none
            }

            :-moz-focusring {
                outline: auto
            }

            :-moz-ui-invalid {
                box-shadow: none
            }

            progress {
                vertical-align: baseline
            }

            ::-webkit-inner-spin-button,::-webkit-outer-spin-button {
                height: auto
            }

            [type=search] {
                -webkit-appearance: textfield;
                outline-offset: -2px
            }

            ::-webkit-search-decoration {
                -webkit-appearance: none
            }

            ::-webkit-file-upload-button {
                -webkit-appearance: button;
                font: inherit
            }

            summary {
                display: list-item
            }

            blockquote,dl,dd,h1,h2,h3,h4,h5,h6,hr,figure,p,pre {
                margin: 0
            }

            fieldset {
                margin: 0;
                padding: 0
            }

            legend {
                padding: 0
            }

            ol,ul,menu {
                list-style: none;
                margin: 0;
                padding: 0
            }

            dialog {
                padding: 0
            }

            textarea {
                resize: vertical
            }

            input::-moz-placeholder,textarea::-moz-placeholder {
                opacity: 1;
                color: #9ca3af
            }

            input::placeholder,textarea::placeholder {
                opacity: 1;
                color: #9ca3af
            }

            button,[role=button] {
                cursor: pointer
            }

            :disabled {
                cursor: default
            }

            img,svg,video,canvas,audio,iframe,embed,object {
                display: block;
                vertical-align: middle
            }

            img,video {
                max-width: 100%;
                height: auto
            }

            [hidden] {
                display: none
            }

            *,:before,:after {
                --tw-border-spacing-x: 0;
                --tw-border-spacing-y: 0;
                --tw-translate-x: 0;
                --tw-translate-y: 0;
                --tw-rotate: 0;
                --tw-skew-x: 0;
                --tw-skew-y: 0;
                --tw-scale-x: 1;
                --tw-scale-y: 1;
                --tw-pan-x: ;
                --tw-pan-y: ;
                --tw-pinch-zoom: ;
                --tw-scroll-snap-strictness: proximity;
                --tw-gradient-from-position: ;
                --tw-gradient-via-position: ;
                --tw-gradient-to-position: ;
                --tw-ordinal: ;
                --tw-slashed-zero: ;
                --tw-numeric-figure: ;
                --tw-numeric-spacing: ;
                --tw-numeric-fraction: ;
                --tw-ring-inset: ;
                --tw-ring-offset-width: 0px;
                --tw-ring-offset-color: #fff;
                --tw-ring-color: rgb(59 130 246 / .5);
                --tw-ring-offset-shadow: 0 0 #0000;
                --tw-ring-shadow: 0 0 #0000;
                --tw-shadow: 0 0 #0000;
                --tw-shadow-colored: 0 0 #0000;
                --tw-blur: ;
                --tw-brightness: ;
                --tw-contrast: ;
                --tw-grayscale: ;
                --tw-hue-rotate: ;
                --tw-invert: ;
                --tw-saturate: ;
                --tw-sepia: ;
                --tw-drop-shadow: ;
                --tw-backdrop-blur: ;
                --tw-backdrop-brightness: ;
                --tw-backdrop-contrast: ;
                --tw-backdrop-grayscale: ;
                --tw-backdrop-hue-rotate: ;
                --tw-backdrop-invert: ;
                --tw-backdrop-opacity: ;
                --tw-backdrop-saturate: ;
                --tw-backdrop-sepia:
            }

            ::backdrop {
                --tw-border-spacing-x: 0;
                --tw-border-spacing-y: 0;
                --tw-translate-x: 0;
                --tw-translate-y: 0;
                --tw-rotate: 0;
                --tw-skew-x: 0;
                --tw-skew-y: 0;
                --tw-scale-x: 1;
                --tw-scale-y: 1;
                --tw-pan-x: ;
                --tw-pan-y: ;
                --tw-pinch-zoom: ;
                --tw-scroll-snap-strictness: proximity;
                --tw-gradient-from-position: ;
                --tw-gradient-via-position: ;
                --tw-gradient-to-position: ;
                --tw-ordinal: ;
                --tw-slashed-zero: ;
                --tw-numeric-figure: ;
                --tw-numeric-spacing: ;
                --tw-numeric-fraction: ;
                --tw-ring-inset: ;
                --tw-ring-offset-width: 0px;
                --tw-ring-offset-color: #fff;
                --tw-ring-color: rgb(59 130 246 / .5);
                --tw-ring-offset-shadow: 0 0 #0000;
                --tw-ring-shadow: 0 0 #0000;
                --tw-shadow: 0 0 #0000;
                --tw-shadow-colored: 0 0 #0000;
                --tw-blur: ;
                --tw-brightness: ;
                --tw-contrast: ;
                --tw-grayscale: ;
                --tw-hue-rotate: ;
                --tw-invert: ;
                --tw-saturate: ;
                --tw-sepia: ;
                --tw-drop-shadow: ;
                --tw-backdrop-blur: ;
                --tw-backdrop-brightness: ;
                --tw-backdrop-contrast: ;
                --tw-backdrop-grayscale: ;
                --tw-backdrop-hue-rotate: ;
                --tw-backdrop-invert: ;
                --tw-backdrop-opacity: ;
                --tw-backdrop-saturate: ;
                --tw-backdrop-sepia:
            }

            .sr-only {
                position: absolute;
                width: 1px;
                height: 1px;
                padding: 0;
                margin: -1px;
                overflow: hidden;
                clip: rect(0,0,0,0);
                white-space: nowrap;
                border-width: 0
            }

            .absolute {
                position: absolute
            }

            .relative {
                position: relative
            }

            .bottom-0 {
                bottom: 0
            }

            .left-0 {
                left: 0
            }

            .right-0 {
                right: 0
            }

            .right-2 {
                right: .5rem
            }

            .top-0 {
                top: 0
            }

            .top-2 {
                top: .5rem
            }

            .z-50 {
                z-index: 50
            }

            .mb-10 {
                margin-bottom: 2.5rem
            }

            .mb-16 {
                margin-bottom: 4rem
            }

            .mb-2 {
                margin-bottom: .5rem
            }

            .mb-4 {
                margin-bottom: 1rem
            }

            .ml-2 {
                margin-left: .5rem
            }

            .mr-2 {
                margin-right: .5rem
            }

            .mt-10 {
                margin-top: 2.5rem
            }

            .mt-12 {
                margin-top: 3rem
            }

            .mt-14 {
                margin-top: 3.5rem
            }

            .mt-2 {
                margin-top: .5rem
            }

            .mt-4 {
                margin-top: 1rem
            }

            .mt-6 {
                margin-top: 1.5rem
            }

            .block {
                display: block
            }

            .inline {
                display: inline
            }

            .flex {
                display: flex
            }

            .inline-flex {
                display: inline-flex
            }

            .hidden {
                display: none
            }

            .h-2 {
                height: .5rem
            }

            .h-2\.5 {
                height: .625rem
            }

            .h-5 {
                height: 1.25rem
            }

            .w-9 {
                width: 2.25rem
            }

            .w-\[280px\] {
                width: 280px
            }

            .w-\[300px\] {
                width: 300px
            }

            .w-\[320px\] {
                width: 320px
            }

            .w-full {
                width: 100%
            }

            @keyframes spin {
                to {
                    transform: rotate(360deg)
                }
            }

            .animate-spin {
                animation: spin 1s linear infinite
            }

            .cursor-pointer {
                cursor: pointer
            }

            .select-none {
                -webkit-user-select: none;
                -moz-user-select: none;
                user-select: none
            }

            .appearance-none {
                -webkit-appearance: none;
                -moz-appearance: none;
                appearance: none
            }

            .flex-row {
                flex-direction: row
            }

            .flex-col {
                flex-direction: column
            }

            .items-center {
                align-items: center
            }

            .justify-center {
                justify-content: center
            }

            .justify-between {
                justify-content: space-between
            }

            .gap-1 {
                gap: .25rem
            }

            .gap-2 {
                gap: .5rem
            }

            .gap-3 {
                gap: .75rem
            }

            .gap-4 {
                gap: 1rem
            }

            .rounded-full {
                border-radius: 9999px
            }

            .rounded-lg {
                border-radius: .5rem
            }

            .rounded-xl {
                border-radius: .75rem
            }

            .border {
                border-width: 1px
            }

            .border-dashed {
                border-style: dashed
            }

            .border-\[\#18191a\] {
                --tw-border-opacity: 1;
                border-color: rgb(24 25 26 / var(--tw-border-opacity))
            }

            .border-\[\#b0b3b8\] {
                --tw-border-opacity: 1;
                border-color: rgb(176 179 184 / var(--tw-border-opacity))
            }

            .border-gray-200 {
                --tw-border-opacity: 1;
                border-color: rgb(229 231 235 / var(--tw-border-opacity))
            }

            .border-opacity-20 {
                --tw-border-opacity: .2
            }

            .border-opacity-30 {
                --tw-border-opacity: .3
            }

            .border-opacity-40 {
                --tw-border-opacity: .4
            }

            .bg-blue-600 {
                --tw-bg-opacity: 1;
                background-color: rgb(37 99 235 / var(--tw-bg-opacity))
            }

            .bg-gray-200 {
                --tw-bg-opacity: 1;
                background-color: rgb(229 231 235 / var(--tw-bg-opacity))
            }

            .bg-gray-50 {
                --tw-bg-opacity: 1;
                background-color: rgb(249 250 251 / var(--tw-bg-opacity))
            }

            .bg-white {
                --tw-bg-opacity: 1;
                background-color: rgb(255 255 255 / var(--tw-bg-opacity))
            }

            .p-3 {
                padding: .75rem
            }

            .px-10 {
                padding-left: 2.5rem;
                padding-right: 2.5rem
            }

            .px-2 {
                padding-left: .5rem;
                padding-right: .5rem
            }

            .px-4 {
                padding-left: 1rem;
                padding-right: 1rem
            }

            .px-5 {
                padding-left: 1.25rem;
                padding-right: 1.25rem
            }

            .px-6 {
                padding-left: 1.5rem;
                padding-right: 1.5rem
            }

            .py-1 {
                padding-top: .25rem;
                padding-bottom: .25rem
            }

            .py-10 {
                padding-top: 2.5rem;
                padding-bottom: 2.5rem
            }

            .py-2 {
                padding-top: .5rem;
                padding-bottom: .5rem
            }

            .py-3 {
                padding-top: .75rem;
                padding-bottom: .75rem
            }

            .pr-5 {
                padding-right: 1.25rem
            }

            .text-center {
                text-align: center
            }

            .text-sm {
                font-size: .875rem;
                line-height: 1.25rem
            }

            .text-xs {
                font-size: .75rem;
                line-height: 1rem
            }

            .font-medium {
                font-weight: 500
            }

            .uppercase {
                text-transform: uppercase
            }

            .text-black {
                --tw-text-opacity: 1;
                color: rgb(0 0 0 / var(--tw-text-opacity))
            }

            .text-gray-700 {
                --tw-text-opacity: 1;
                color: rgb(55 65 81 / var(--tw-text-opacity))
            }

            .text-gray-900 {
                --tw-text-opacity: 1;
                color: rgb(17 24 39 / var(--tw-text-opacity))
            }

            .text-green-500 {
                --tw-text-opacity: 1;
                color: rgb(34 197 94 / var(--tw-text-opacity))
            }

            .text-red-500 {
                --tw-text-opacity: 1;
                color: rgb(239 68 68 / var(--tw-text-opacity))
            }

            .text-yellow-400 {
                --tw-text-opacity: 1;
                color: rgb(250 204 21 / var(--tw-text-opacity))
            }

            .text-yellow-500 {
                --tw-text-opacity: 1;
                color: rgb(234 179 8 / var(--tw-text-opacity))
            }

            .text-opacity-40 {
                --tw-text-opacity: .4
            }

            .opacity-60 {
                opacity: .6
            }

            .transition-colors {
                transition-property: color,background-color,border-color,text-decoration-color,fill,stroke;
                transition-timing-function: cubic-bezier(.4,0,.2,1);
                transition-duration: .15s
            }

            .after\:absolute:after {
                content: var(--tw-content);
                position: absolute
            }

            .after\:left-\[2px\]:after {
                content: var(--tw-content);
                left: 2px
            }

            .after\:top-\[2px\]:after {
                content: var(--tw-content);
                top: 2px
            }

            .after\:h-4:after {
                content: var(--tw-content);
                height: 1rem
            }

            .after\:w-4:after {
                content: var(--tw-content);
                width: 1rem
            }

            .after\:rounded-full:after {
                content: var(--tw-content);
                border-radius: 9999px
            }

            .after\:border:after {
                content: var(--tw-content);
                border-width: 1px
            }

            .after\:border-gray-300:after {
                content: var(--tw-content);
                --tw-border-opacity: 1;
                border-color: rgb(209 213 219 / var(--tw-border-opacity))
            }

            .after\:bg-white:after {
                content: var(--tw-content);
                --tw-bg-opacity: 1;
                background-color: rgb(255 255 255 / var(--tw-bg-opacity))
            }

            .after\:transition-all:after {
                content: var(--tw-content);
                transition-property: all;
                transition-timing-function: cubic-bezier(.4,0,.2,1);
                transition-duration: .15s
            }

            .after\:content-\[\'\'\]:after{--tw-content: '';content:var(--tw-content)}.hover\:border-opacity-80:hover{--tw-border-opacity: .8}.hover\:bg-gray-200:hover{--tw-bg-opacity: 1;background-color:rgb(229 231 235 / var(--tw-bg-opacity))}.focus\:border-blue-500:focus{--tw-border-opacity: 1;border-color:rgb(59 130 246 / var(--tw-border-opacity))}.focus\:outline-none:focus{outline:2px solid transparent;outline-offset:2px}.focus\:ring-4:focus{--tw-ring-offset-shadow: var(--tw-ring-inset) 0 0 0 var(--tw-ring-offset-width) var(--tw-ring-offset-color);--tw-ring-shadow: var(--tw-ring-inset) 0 0 0 calc(4px + var(--tw-ring-offset-width)) var(--tw-ring-color);box-shadow:var(--tw-ring-offset-shadow),var(--tw-ring-shadow),var(--tw-shadow, 0 0 #0000)}.focus\:ring-blue-500:focus{--tw-ring-opacity: 1;--tw-ring-color: rgb(59 130 246 / var(--tw-ring-opacity))}.focus\:ring-gray-200:focus{--tw-ring-opacity: 1;--tw-ring-color: rgb(229 231 235 / var(--tw-ring-opacity))}.focus\:ring-gray-300:focus{--tw-ring-opacity: 1;--tw-ring-color: rgb(209 213 219 / var(--tw-ring-opacity))}.peer:checked~.peer-checked\:bg-blue-600{--tw-bg-opacity: 1;background-color:rgb(37 99 235 / var(--tw-bg-opacity))}.peer:checked~.peer-checked\:bg-green-600{--tw-bg-opacity: 1;background-color:rgb(22 163 74 / var(--tw-bg-opacity))}.peer:checked~.peer-checked\:after\:translate-x-full:after{content:var(--tw-content);--tw-translate-x: 100%;transform:translate(var(--tw-translate-x),var(--tw-translate-y)) rotate(var(--tw-rotate)) skew(var(--tw-skew-x)) skewY(var(--tw-skew-y)) scaleX(var(--tw-scale-x)) scaleY(var(--tw-scale-y))}.peer:checked~.peer-checked\:after\:border-white:after{content:var(--tw-content);--tw-border-opacity: 1;border-color:rgb(255 255 255 / var(--tw-border-opacity))}.peer:focus~.peer-focus\:outline-none{outline:2px solid transparent;outline-offset:2px}.peer:focus~.peer-focus\:ring-4{--tw-ring-offset-shadow: var(--tw-ring-inset) 0 0 0 var(--tw-ring-offset-width) var(--tw-ring-offset-color);--tw-ring-shadow: var(--tw-ring-inset) 0 0 0 calc(4px + var(--tw-ring-offset-width)) var(--tw-ring-color);box-shadow:var(--tw-ring-offset-shadow),var(--tw-ring-shadow),var(--tw-shadow, 0 0 #0000)}.peer:focus~.peer-focus\:ring-blue-300{--tw-ring-opacity: 1;--tw-ring-color: rgb(147 197 253 / var(--tw-ring-opacity))}.peer:focus~.peer-focus\:ring-green-300{--tw-ring-opacity: 1;--tw-ring-color: rgb(134 239 172 / var(--tw-ring-opacity))}:is(.dark .dark\:border-\[\#242526\]){--tw-border-opacity: 1;border-color:rgb(36 37 38 / var(--tw-border-opacity))}:is(.dark .dark\:border-\[\#3a3b3c\]){--tw-border-opacity: 1;border-color:rgb(58 59 60 / var(--tw-border-opacity))}:is(.dark .dark\:border-\[\#e4e6eb\]){--tw-border-opacity: 1;border-color:rgb(228 230 235 / var(--tw-border-opacity))}:is(.dark .dark\:border-gray-600){--tw-border-opacity: 1;border-color:rgb(75 85 99 / var(--tw-border-opacity))}:is(.dark .dark\:border-opacity-20){--tw-border-opacity: .2}:is(.dark .dark\:bg-\[\#18191a\]){--tw-bg-opacity: 1;background-color:rgb(24 25 26 / var(--tw-bg-opacity))}:is(.dark .dark\:bg-\[\#242526\]){--tw-bg-opacity: 1;background-color:rgb(36 37 38 / var(--tw-bg-opacity))}:is(.dark .dark\:bg-gray-700){--tw-bg-opacity: 1;background-color:rgb(55 65 81 / var(--tw-bg-opacity))}:is(.dark .dark\:bg-transparent){background-color:transparent}:is(.dark .dark\:text-\[\#b0b3b8\]){--tw-text-opacity: 1;color:rgb(176 179 184 / var(--tw-text-opacity))}:is(.dark .dark\:text-\[\#e4e6eb\]){--tw-text-opacity: 1;color:rgb(228 230 235 / var(--tw-text-opacity))}:is(.dark .dark\:text-white){--tw-text-opacity: 1;color:rgb(255 255 255 / var(--tw-text-opacity))}:is(.dark .dark\:text-opacity-60){--tw-text-opacity: .6}:is(.dark .dark\:placeholder-gray-400)::-moz-placeholder{--tw-placeholder-opacity: 1;color:rgb(156 163 175 / var(--tw-placeholder-opacity))}:is(.dark .dark\:placeholder-gray-400)::placeholder{--tw-placeholder-opacity: 1;color:rgb(156 163 175 / var(--tw-placeholder-opacity))}:is(.dark .dark\:opacity-10){opacity:.1}:is(.dark .dark\:hover\:border-opacity-80:hover){--tw-border-opacity: .8}:is(.dark .dark\:hover\:bg-\[\#3a3b3c\]:hover){--tw-bg-opacity: 1;background-color:rgb(58 59 60 / var(--tw-bg-opacity))}:is(.dark .dark\:focus\:border-blue-500:focus){--tw-border-opacity: 1;border-color:rgb(59 130 246 / var(--tw-border-opacity))}:is(.dark .dark\:focus\:ring-\[\#3a3b3c\]:focus){--tw-ring-opacity: 1;--tw-ring-color: rgb(58 59 60 / var(--tw-ring-opacity))}:is(.dark .dark\:focus\:ring-blue-500:focus){--tw-ring-opacity: 1;--tw-ring-color: rgb(59 130 246 / var(--tw-ring-opacity))}:is(.dark .peer:focus~.dark\:peer-focus\:ring-blue-800){--tw-ring-opacity: 1;--tw-ring-color: rgb(30 64 175 / var(--tw-ring-opacity))}:is(.dark .peer:focus~.dark\:peer-focus\:ring-green-800){--tw-ring-opacity: 1;--tw-ring-color: rgb(22 101 52 / var(--tw-ring-opacity))}</style>
    </head>
    <body class='dark:bg-[#18191a] bg-white dark:text-[#e4e6eb] px-6'>
        <div class='flex flex-col items-center mt-12 mb-16'>
            <img src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAOcAAAAvCAYAAAAYT935AAAACXBIWXMAAA8SAAAPEgEhm/IzAAAOcUlEQVR42u1daZBVxRX+zgADgggOIMiiYECIQIIKgopGlKgISEoRDBD3JVEj7hhRU26UKAbcIktcUlDiThJE4wKyWSAlAiKIsoksIwzDvg4zfPnxzo1NT9/lvTdvmMfcr+rVm3f79Onu2+f0cs7pHoEDJOsAaAKgIYAG+qlvffIAHAWgOoBcxzcA7AdQ5PjeA6AQwGbHpwBAPoD1IrILMWJUUgjJKgBuB9ADQAsAxwOoVUHqtxPABgCrAUwCME5EGHdbjEoBkk8ze3Bv3GMxKtPMWaDL1GzAUhFpG3dbjMqAnCxSTOgeOEaMSqOcMWLEiJXTiSIA78ZdESNGxVLOVQDOBvB23BUxYlQc5XwPwGkAtgAYE3dFjBiHXzmLAAwWkcsB7AXwJoA6cVfEiHEoqpZzeasB9BORL/X3UwA6ZrpQkrkABqSYfYaIrI5FpXxBsjGATgDa6OCdC2CHytAsEfmhMryE8sK7Ghbolfu7FHhsTrGNddOo95WxqpSbLArJXiRnRuiX6SR/cyS/DyGZ6XC4IgD3icizRiecCGABgGOT5FUoIvVTUU4AWwEsAfBgktm/FJF1sepkXDFrAHgNQP8ksz4B4KFsDOskuRxAM+PRMhHpUF4z5yqSnawKVSM5N0V+6c6c02M1qLCC+noacnZ7Frb3GEc73i6vPeckANeJyDbr+TAAnWNxjGEIancAv/dZdU0GsEx/twPQG6UNmcNIvikiG7Oo2a4w1CWZ3nPuJznYpxN6kjyYBu945jwylXOCo69/IHmCg7YDyS0O+luzrM03ONrQN5Mz5w8A+ovIPEdlmgL4JwBJg39BFrx074zr9nT2QSSrI3F0b5uIHCwPYwyAugB2i0hROb+2U117SRH5sZSRRGQhyftR2jfeFcCLRntOMGZYisgaI60JgFYAagP4CcBCETmQytIUwMlInHfOUV7fiMj+ANtHXf3ZxUGyg2TzTMyck7Rwv4YMJ7ktjc9Kkhce7pmTZHeS60he7Ak1yfO1/fnG+9hHcgbJq0hWjci7FcmXSK41+JSQXETycZINAvK+TfId/TuH5OVqIV+g9a3jGgBI3kpyFskio7zVJP9OspVBe6vyqaG/T9Xfo5J4d8cq7/et55sc8tQ7gE8Ltdaan5FGei1rhbZPn3dUWhtbST7lekeOsquRvFbfWbGD1x6Sb5Fs58j7YhL6tK4slLOI5B0VfDYrS+XspbyuJ5lL8jX9vYbkKyQf047+wBD46STrBc1aJO826GeRfJbkvSTHqYKR5HaSfXx4TCe5WOv0vtJvIjlP04626NuSXKF0+STHann3kXxZ85aQvMEYXGkop5BcSnKXziBR3t1tyuOP1vPvHXL1qVdWCn10hoPfQB9lMrHskJmrNN/TjHcWhgMkb7Hyz0xCrz5MVzlXkzwjC5aamVDOISTHq3BeTTLHQduO5Hyl/0xvnXDxHGoIR1cf5e1Lcr3OCD18lDNfZ9h8kr1ddVLa1roaKdF25LqW5yQf1fIGqfLSVBiSd+izm6Msm3UFUEqZjQHOxnKSN5HMS7KPrnfwKoko0wtdgwLJi3U1lCyuMdq/NYl8w9NRzn+RPBZZgAwp5wKd6c4Moa+hS/JSG35NP1MFZ03QtsBQ9n0kC0jWdihnMcnNJH8VwKOKCiBJ9o/Q3ptJbiT5sUM587Q+8yPw6aj5xzrSTiG5N0DWiklO06V1owhljQrgtVi3Di/7zNilXDM6mG33WTVO0VXOv0nu8FnmNiJ5nM66K/R92thkpK8geRlSXMbemWWWsbrG3uLTiJ+zQ5STJB+NWL4XDfVfR9qHmtY1Iq/7lP4uh3LS23cG5O+ndK9FNRTpQExbOTV9vD4/PYTP6CA6HQSi4KD2z+kBZU3zUfA/qeHL3D+Odi1vLX6TfVaNp1h0J+rqwMYwi+4uB81FroYkiy5ZaKqva3RQVANUzxDlLAoy0DgEvIDkbtM4RLKBNwsn0ZZmmmemj3JeHpLf24+2SaLMzgHKeY4+HxOQv5bOKl+GlNNbjUxRlfR529hmvGsbV/iUWVO3CzaaGq4bG4UkG/rw6+BYQi+yaF518Dze5pWKK+UZknvT0RUAj4jI7MOgp7NF5Lwy4vWViERy7YgISS4G0A1APQCes/xc/Z4WtVARWUtyLYDOJMXhrpkXIPw5WuZyEVmWRFvnqRvLNRjNBvAtgAEk7xGRnQ6aK9RtMTqkbZN10LkWwCAAQbOxALgNwG4A9xvPG6L01TszAbzjU+YekjNQOgiiOYB1AC51ZBvhF/Cgrp5vcWiQQWurr9pb2QrVDZO2cp6VplDPBfAVsh9Lk6Tfot95hnJ6lsH+JC9IglceEqc06qO07zcoUKOuKsnHyVTcGFzO90kbC2CkCvhYB4sbkbjm9I0IZW0HMArAKJKtAfRRBTnbJ8sQkh+IyEwfwQeA50N8zmscz6rpt2swHxfSjNWWcnp3Oe9Xo6AdHbTYVb+qh0Gge4rIniNAObcmSV+s31UsZQESYVv5SfBaqN8l1vN9IhK0qvEMeNtTaG9hQNp4AE8CuMlWTt2XnQXgpWQvCReR75A4VvgUybYAhgPo6TMzBynnkpCimjmeeQNoY/s9iEhYpFpT6/cuIzDhFwBsa/DXLiZByjkFwBCt+LsAaqYpzGsAXCgiW3Bk4EAZ8PCU5AURmVwG/EpC0r0lZyqXhtcOUKJCNUQNJHm6iJjW2+v1e4xjmT0cwDE6cBXrO33QFaEkIkvUx/sZgHOsZDPMz6Wc60Pa1t7xHtfq37Z/ekPIvrkqElFDfnlc9VscVTkPAngYwDCdapeQ/A7uEKuoKFDFXI8YJtZay9tMoxCJf4lxcgp5W4WkjwEwUJew81VQqwO4CsAXIrLIkedCAB2sZ5MAzPEZBEpIznEo544Q4W/mN3vqmVDb9TTH2Dtvt/awLXz2+h4GOCay6SH1c86cOYaAePuVi0TkCa9wkv3SVMydAHqIyPcpWY/IqiT/oOFk7Y8w5Zyl392TeB85JB9JJdBbREp0z9/BZR0MKPMkXY4FGtvUMDTQiEa6VAXbzxDkUpjbTHeHVQ9BIobWxkpNd+3nAKCXD7+jdNlsw9wb24azo32MRF6s7UOOpMkhyrnU78Vfog71t0g2s4Tg8TRPkewjeX6KSlmT5GB1znv4JkVemQhCeDLJfG9ovnbWcy+kq1OS5T9oPZ9OcleE/H92+d5C8ozyc6VYdF7EkBfy95G6pWr60PfzkZtRdoCLOvFH+9C3U5rWPuk7bL+1Bga4zhXnq9J6dDc6aNaSPNXi14LkNw7ar8xILSMAxESLZASpPslP0gztKwnzufmUnUfyrz6+qs1HoHJ21+dz/ML7DNo62rkHPD9cCspZk+QG9dN2ikB/ngZvzIqgnPV0QJ5HsrkO7M8F0Fch+bWP/OzW0MePdPLY73f9jcGvb4g8fqorsEkaueNCL6uONayDCGYwzifKb4pP/fbbcQEBsbn56uOdENQZXXwqkyxuTFJ4m5IcqbGXFfY8Z1krp6Y9p2nv+cWRkjyB5Gylu86RHkk5lbabCus2kpf4LSH1ZMsujUp6J0w5Nd8EI7yTamUNom/vExoXBUtJHmfweiRNmf2LTx0viBA074pIGujg9Z+QfM84DUIaUzgCP/t4UsVQERkXUVDaqFV4YBmUG4aWyRxx8qzMIjIyw/W6Uw1xgwGcq6PnbDVGNEfiFrqrtb+Gisgr6RQmIp+RvAzARABTdNCaBGC52iFaA+gL4EwAzwB4GtEv/vYMQ30AfC4iS0LqsphkNwCva7lRMQnATZZbw97PFQF4TD9B2A3gdr/3KiJTNS56vO45w7AOwCARmeFIG4GEO8jvWtrFtoLUIjmxjM51joyolJ11eZHMnvZw3L43N9Mzp2k5JDnVMUof1LC7tgF5I8+cRp7mGkrmmrnmaUywKK0X9he29BaS3yrtoCTqcpTeDvBFwAmSzXqCpasPj+WusDmSV5L8zsGvQIPgmySxuntB6+FaNn+u8bvVQ/j8VmldS+H/R0WJxghOA3BKGcwA4wFcHRSNoQG+98MdeRHqCkjx9r0clHYmR0WRiGyyLHz1AOzUaJaodaiHxH8C3xh26l5Pp3gn7HcAWBLmH9Y439xU3FUkq2n/N9LZeoW+axo0cwG0EZG6EfjNVKtpExHZl0J9aussmodE0MZW9Sps8JMtkrXUM2BaeieKyADD0tsSif/YXk1nt+UiUpxC/apo/RrrDFgAYLXjvqwoctnAWjHmq1Ud0KMuZYH3/U7868a/v1qu0sFmxEh3z9yD5Aj7REVInlw90jU3Au0vta/+Vs7t6uSQlweyua+qJuNjC8DnAK6wRyGd3q8BcI+OWjEOP2oBuFtnpesi5umDRMjZzAi03sHrseXcrlTC9ir8SJouvrYPCeudnEOsO3XKAvHMmX5/V1dr/H69kjLKfn2l7qlahNA2VhfI1MPQrpEOeWlZmZVzlRlpQrIhySfVRJ8JxMpZNn3ekeROXareYd+qYNB1MRzrQyMYgl51+QrLqU1THTcQVKmsyvmTNzKRPEmtXnszfIN8rJxl1+/djOirbepQ/4fOQBMM62YxyQd87kh6WK3Es0n+6F1M5Rd+l+H22Df4zc/2Pkr1yBgB9ABQi+REJI7sVIlFPnugvs6WAK5E4v+TNEfiaFcuEtbRZUgcUB5r3vnq2L96W5qVSPgqh5X3/y3RKy034NDTHx9nfR+RKf8jo0UAfl3O9U3JlRIjspCLKi7jt1ExlLM4i2a9jSLSKO62GJUBOfj5VH02YH7cZTEqk3LeAmBTFtT1RyT8czFiVI5lre41jgZwmhoFmiBxB0oTAMcjcVi2HhL/+jtj2x0A25A4qb9ZN/brjc8qAAtC7seJEePIU86IxoJqSESVeMqah0SsqHezmP0NJK7EKHJ87zUUsRAJQ09J3B0xYvyM/wF81Xv+eS0KngAAAABJRU5ErkJggg==' viewBox='0 0 840 197' width='231' height='47' class='dark:text-[#e4e6eb]'>
            <!-- Upload Column -->
            <div id='uploadColumn' class='flex flex-col justify-center mt-12 mb-4'>
                <!-- Create a button -->
                <form>
                    <button id='uploadButton' class='dark:text-white bg-gray-50 border border-[#b0b3b8] border-opacity-40 hover:bg-gray-200 text-gray-700 focus:outline-none focus:ring-4 focus:ring-gray-200 rounded-full px-5 py-3 mr-2 flex flex-row gap-3 items-center dark:bg-[#242526] dark:hover:bg-[#3a3b3c] dark:focus:ring-[#3a3b3c] dark:border-[#3a3b3c]'>
                        <svg xmlns='http://www.w3.org/2000/svg' width='20' height='20' viewBox='0 0 24 24' fill='none' stroke='currentColor' stroke-width='1.5' stroke-linecap='round' stroke-linejoin='round' class='lucide lucide-file-up'>
                            <path d='M14.5 2H6a2 2 0 0 0-2 2v16a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V7.5L14.5 2z'/>
                            <polyline points='14 2 14 8 20 8'/>
                            <path d='M12 12v6'/>
                            <path d='m15 15-3-3-3 3'/>
                        </svg>
                        <span>Select File
            </span>
                    </button>
                    <input type='file' id='fileInput' class='hidden' accept='.bin,.bin.gz' onchange='onFileInput(files)'>
                </form>
            </div>
            <!-- Progress Column -->
            <div id='progressColumn' class='flex flex-col justify-center mt-14 mb-10 hidden'>
                <p id='progressTitle' class='text-center mb-2 text-sm dark:text-[#b0b3b8]'></p>
                <div class='flex flex-row items-center gap-4 w-[280px]'>
                    <div class='w-full bg-gray-200 rounded-full h-2.5 dark:bg-[#242526]'>
                        <div id='progressBar' class='bg-blue-600 h-2.5 rounded-full' style='width: 0%'></div>
                    </div>
                    <p id='progressValue' class='text-sm'>0%
          </p>
                </div>
            </div>
            <!-- Success Column -->
            <div id='successColumn' class='flex flex-col items-center gap-4 mt-12 hidden'>
                <svg xmlns='http://www.w3.org/2000/svg' width='42' height='42' viewBox='0 0 24 24' fill='none' stroke='currentColor' stroke-width='2' stroke-linecap='round' stroke-linejoin='round' class='text-green-500'>
                    <path d='M3.85 8.62a4 4 0 0 1 4.78-4.77 4 4 0 0 1 6.74 0 4 4 0 0 1 4.78 4.78 4 4 0 0 1 0 6.74 4 4 0 0 1-4.77 4.78 4 4 0 0 1-6.75 0 4 4 0 0 1-4.78-4.77 4 4 0 0 1 0-6.76Z'/>
                    <path d='m9 12 2 2 4-4'/>
                </svg>
                <p>Update Successful
        </p>
                <button onclick='resetView()' type='button' class='dark:text-white bg-gray-50 border border-[#b0b3b8] border-opacity-40 hover:bg-gray-200 text-gray-700 text-xs focus:outline-none focus:ring-4 focus:ring-gray-300 font-medium rounded-full px-4 py-2 mr-2 mt-2 flex flex-row gap-2 items-center dark:bg-[#242526] dark:hover:bg-[#3a3b3c] dark:focus:ring-[#3a3b3c] dark:border-[#3a3b3c]'>
                    <svg xmlns='http://www.w3.org/2000/svg' width='14' height='14' viewBox='0 0 24 24' fill='none' stroke='currentColor' stroke-width='2' stroke-linecap='round' stroke-linejoin='round' class='lucide lucide-arrow-left'>
                        <path d='m12 19-7-7 7-7'/>
                        <path d='M19 12H5'/>
                    </svg>
                    Go Back
        
                </button>
            </div>
            <!-- Error Column -->
            <div id='errorColumn' class='flex flex-col items-center gap-2 mt-12 hidden'>
                <svg xmlns='http://www.w3.org/2000/svg' width='42' height='42' viewBox='0 0 24 24' fill='none' stroke='currentColor' stroke-width='2' stroke-linecap='round' stroke-linejoin='round' class='text-red-500'>
                    <path d='m21.73 18-8-14a2 2 0 0 0-3.48 0l-8 14A2 2 0 0 0 4 21h16a2 2 0 0 0 1.73-3Z'/>
                    <path d='M12 9v4'/>
                    <path d='M12 17h.01'/>
                </svg>
                <p id='errorTitle' class='mt-2'>Unexpected Error
        </p>
                <p id='errorReason' class='text-xs dark:text-[#b0b3b8]'>Please try again
        </p>
                <button onclick='resetView()' type='button' class='dark:text-white bg-gray-50 border border-[#b0b3b8] border-opacity-40 hover:bg-gray-200 text-gray-700 text-xs focus:outline-none focus:ring-4 focus:ring-gray-300 font-medium rounded-full px-4 py-2 mr-2 mt-4 flex flex-row gap-2 items-center dark:bg-[#242526] dark:hover:bg-[#3a3b3c] dark:focus:ring-[#3a3b3c] dark:border-[#3a3b3c]'>
                    <svg xmlns='http://www.w3.org/2000/svg' width='14' height='14' viewBox='0 0 24 24' fill='none' stroke='currentColor' stroke-width='2' stroke-linecap='round' stroke-linejoin='round' class='lucide lucide-arrow-left'>
                        <path d='m12 19-7-7 7-7'/>
                        <path d='M19 12H5'/>
                    </svg>
                    Go Back
        
                </button>
            </div>
        </div>
    </body>
</html>
)rawliteral";

#endif
