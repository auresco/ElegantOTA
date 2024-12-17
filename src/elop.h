#ifndef elop_h
#define elop_h

#include <Arduino.h>

const char ELEGANT_HTML[] PROGMEM = R"rawliteral(
<!doctype html>
<html lang='en'>
<head>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <link rel='icon' href='data:image/png;base64,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' type='image/png'>
    <title>OTA Update</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; margin: 0; padding: 0; background: #18191a; color: #e4e6eb; }
        button { padding: 10px 20px; margin: 10px; border: 1px solid #555; background: #242526; color: #fff; border-radius: 5px; cursor: pointer; }
        button:hover { background: #3a3b3c; }
        .hidden { display: none; }
        #progressBar { width: 0%; height: 20px; background: #4caf50; margin: 10px auto; }
        .container { margin-top: 50px; }
        .logo-container { display: flex; justify-content: center; align-items: center; height: 47px; text-align: center; margin-top: 20px;}
    </style>
</head>
<body>
    <div class='logo-container'>
        <img src='data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAOcAAAAvCAYAAAAYT935AAAACXBIWXMAAA8SAAAPEgEhm/IzAAAOcUlEQVR42u1daZBVxRX+zgADgggOIMiiYECIQIIKgopGlKgISEoRDBD3JVEj7hhRU26UKAbcIktcUlDiThJE4wKyWSAlAiKIsoksIwzDvg4zfPnxzo1NT9/lvTdvmMfcr+rVm3f79Onu2+f0cs7pHoEDJOsAaAKgIYAG+qlvffIAHAWgOoBcxzcA7AdQ5PjeA6AQwGbHpwBAPoD1IrILMWJUUgjJKgBuB9ADQAsAxwOoVUHqtxPABgCrAUwCME5EGHdbjEoBkk8ze3Bv3GMxKtPMWaDL1GzAUhFpG3dbjMqAnCxSTOgeOEaMSqOcMWLEiJXTiSIA78ZdESNGxVLOVQDOBvB23BUxYlQc5XwPwGkAtgAYE3dFjBiHXzmLAAwWkcsB7AXwJoA6cVfEiHEoqpZzeasB9BORL/X3UwA6ZrpQkrkABqSYfYaIrI5FpXxBsjGATgDa6OCdC2CHytAsEfmhMryE8sK7Ghbolfu7FHhsTrGNddOo95WxqpSbLArJXiRnRuiX6SR/cyS/DyGZ6XC4IgD3icizRiecCGABgGOT5FUoIvVTUU4AWwEsAfBgktm/FJF1sepkXDFrAHgNQP8ksz4B4KFsDOskuRxAM+PRMhHpUF4z5yqSnawKVSM5N0V+6c6c02M1qLCC+noacnZ7Frb3GEc73i6vPeckANeJyDbr+TAAnWNxjGEIancAv/dZdU0GsEx/twPQG6UNmcNIvikiG7Oo2a4w1CWZ3nPuJznYpxN6kjyYBu945jwylXOCo69/IHmCg7YDyS0O+luzrM03ONrQN5Mz5w8A+ovIPEdlmgL4JwBJg39BFrx074zr9nT2QSSrI3F0b5uIHCwPYwyAugB2i0hROb+2U117SRH5sZSRRGQhyftR2jfeFcCLRntOMGZYisgaI60JgFYAagP4CcBCETmQytIUwMlInHfOUV7fiMj+ANtHXf3ZxUGyg2TzTMyck7Rwv4YMJ7ktjc9Kkhce7pmTZHeS60he7Ak1yfO1/fnG+9hHcgbJq0hWjci7FcmXSK41+JSQXETycZINAvK+TfId/TuH5OVqIV+g9a3jGgBI3kpyFskio7zVJP9OspVBe6vyqaG/T9Xfo5J4d8cq7/et55sc8tQ7gE8Ltdaan5FGei1rhbZPn3dUWhtbST7lekeOsquRvFbfWbGD1x6Sb5Fs58j7YhL6tK4slLOI5B0VfDYrS+XspbyuJ5lL8jX9vYbkKyQf047+wBD46STrBc1aJO826GeRfJbkvSTHqYKR5HaSfXx4TCe5WOv0vtJvIjlP04626NuSXKF0+STHann3kXxZ85aQvMEYXGkop5BcSnKXziBR3t1tyuOP1vPvHXL1qVdWCn10hoPfQB9lMrHskJmrNN/TjHcWhgMkb7Hyz0xCrz5MVzlXkzwjC5aamVDOISTHq3BeTTLHQduO5Hyl/0xvnXDxHGoIR1cf5e1Lcr3OCD18lDNfZ9h8kr1ddVLa1roaKdF25LqW5yQf1fIGqfLSVBiSd+izm6Msm3UFUEqZjQHOxnKSN5HMS7KPrnfwKoko0wtdgwLJi3U1lCyuMdq/NYl8w9NRzn+RPBZZgAwp5wKd6c4Moa+hS/JSG35NP1MFZ03QtsBQ9n0kC0jWdihnMcnNJH8VwKOKCiBJ9o/Q3ptJbiT5sUM587Q+8yPw6aj5xzrSTiG5N0DWiklO06V1owhljQrgtVi3Di/7zNilXDM6mG33WTVO0VXOv0nu8FnmNiJ5nM66K/R92thkpK8geRlSXMbemWWWsbrG3uLTiJ+zQ5STJB+NWL4XDfVfR9qHmtY1Iq/7lP4uh3LS23cG5O+ndK9FNRTpQExbOTV9vD4/PYTP6CA6HQSi4KD2z+kBZU3zUfA/qeHL3D+Odi1vLX6TfVaNp1h0J+rqwMYwi+4uB81FroYkiy5ZaKqva3RQVANUzxDlLAoy0DgEvIDkbtM4RLKBNwsn0ZZmmmemj3JeHpLf24+2SaLMzgHKeY4+HxOQv5bOKl+GlNNbjUxRlfR529hmvGsbV/iUWVO3CzaaGq4bG4UkG/rw6+BYQi+yaF518Dze5pWKK+UZknvT0RUAj4jI7MOgp7NF5Lwy4vWViERy7YgISS4G0A1APQCes/xc/Z4WtVARWUtyLYDOJMXhrpkXIPw5WuZyEVmWRFvnqRvLNRjNBvAtgAEk7xGRnQ6aK9RtMTqkbZN10LkWwCAAQbOxALgNwG4A9xvPG6L01TszAbzjU+YekjNQOgiiOYB1AC51ZBvhF/Cgrp5vcWiQQWurr9pb2QrVDZO2cp6VplDPBfAVsh9Lk6Tfot95hnJ6lsH+JC9IglceEqc06qO07zcoUKOuKsnHyVTcGFzO90kbC2CkCvhYB4sbkbjm9I0IZW0HMArAKJKtAfRRBTnbJ8sQkh+IyEwfwQeA50N8zmscz6rpt2swHxfSjNWWcnp3Oe9Xo6AdHbTYVb+qh0Gge4rIniNAObcmSV+s31UsZQESYVv5SfBaqN8l1vN9IhK0qvEMeNtTaG9hQNp4AE8CuMlWTt2XnQXgpWQvCReR75A4VvgUybYAhgPo6TMzBynnkpCimjmeeQNoY/s9iEhYpFpT6/cuIzDhFwBsa/DXLiZByjkFwBCt+LsAaqYpzGsAXCgiW3Bk4EAZ8PCU5AURmVwG/EpC0r0lZyqXhtcOUKJCNUQNJHm6iJjW2+v1e4xjmT0cwDE6cBXrO33QFaEkIkvUx/sZgHOsZDPMz6Wc60Pa1t7xHtfq37Z/ekPIvrkqElFDfnlc9VscVTkPAngYwDCdapeQ/A7uEKuoKFDFXI8YJtZay9tMoxCJf4lxcgp5W4WkjwEwUJew81VQqwO4CsAXIrLIkedCAB2sZ5MAzPEZBEpIznEo544Q4W/mN3vqmVDb9TTH2Dtvt/awLXz2+h4GOCay6SH1c86cOYaAePuVi0TkCa9wkv3SVMydAHqIyPcpWY/IqiT/oOFk7Y8w5Zyl392TeB85JB9JJdBbREp0z9/BZR0MKPMkXY4FGtvUMDTQiEa6VAXbzxDkUpjbTHeHVQ9BIobWxkpNd+3nAKCXD7+jdNlsw9wb24azo32MRF6s7UOOpMkhyrnU78Vfog71t0g2s4Tg8TRPkewjeX6KSlmT5GB1znv4JkVemQhCeDLJfG9ovnbWcy+kq1OS5T9oPZ9OcleE/H92+d5C8ozyc6VYdF7EkBfy95G6pWr60PfzkZtRdoCLOvFH+9C3U5rWPuk7bL+1Bga4zhXnq9J6dDc6aNaSPNXi14LkNw7ar8xILSMAxESLZASpPslP0gztKwnzufmUnUfyrz6+qs1HoHJ21+dz/ML7DNo62rkHPD9cCspZk+QG9dN2ikB/ngZvzIqgnPV0QJ5HsrkO7M8F0Fch+bWP/OzW0MePdPLY73f9jcGvb4g8fqorsEkaueNCL6uONayDCGYwzifKb4pP/fbbcQEBsbn56uOdENQZXXwqkyxuTFJ4m5IcqbGXFfY8Z1krp6Y9p2nv+cWRkjyB5Gylu86RHkk5lbabCus2kpf4LSH1ZMsujUp6J0w5Nd8EI7yTamUNom/vExoXBUtJHmfweiRNmf2LTx0viBA074pIGujg9Z+QfM84DUIaUzgCP/t4UsVQERkXUVDaqFV4YBmUG4aWyRxx8qzMIjIyw/W6Uw1xgwGcq6PnbDVGNEfiFrqrtb+Gisgr6RQmIp+RvAzARABTdNCaBGC52iFaA+gL4EwAzwB4GtEv/vYMQ30AfC4iS0LqsphkNwCva7lRMQnATZZbw97PFQF4TD9B2A3gdr/3KiJTNS56vO45w7AOwCARmeFIG4GEO8jvWtrFtoLUIjmxjM51joyolJ11eZHMnvZw3L43N9Mzp2k5JDnVMUof1LC7tgF5I8+cRp7mGkrmmrnmaUywKK0X9he29BaS3yrtoCTqcpTeDvBFwAmSzXqCpasPj+WusDmSV5L8zsGvQIPgmySxuntB6+FaNn+u8bvVQ/j8VmldS+H/R0WJxghOA3BKGcwA4wFcHRSNoQG+98MdeRHqCkjx9r0clHYmR0WRiGyyLHz1AOzUaJaodaiHxH8C3xh26l5Pp3gn7HcAWBLmH9Y439xU3FUkq2n/N9LZeoW+axo0cwG0EZG6EfjNVKtpExHZl0J9aussmodE0MZW9Sps8JMtkrXUM2BaeieKyADD0tsSif/YXk1nt+UiUpxC/apo/RrrDFgAYLXjvqwoctnAWjHmq1Ud0KMuZYH3/U7868a/v1qu0sFmxEh3z9yD5Aj7REVInlw90jU3Au0vta/+Vs7t6uSQlweyua+qJuNjC8DnAK6wRyGd3q8BcI+OWjEOP2oBuFtnpesi5umDRMjZzAi03sHrseXcrlTC9ir8SJouvrYPCeudnEOsO3XKAvHMmX5/V1dr/H69kjLKfn2l7qlahNA2VhfI1MPQrpEOeWlZmZVzlRlpQrIhySfVRJ8JxMpZNn3ekeROXareYd+qYNB1MRzrQyMYgl51+QrLqU1THTcQVKmsyvmTNzKRPEmtXnszfIN8rJxl1+/djOirbepQ/4fOQBMM62YxyQd87kh6WK3Es0n+6F1M5Rd+l+H22Df4zc/2Pkr1yBgB9ABQi+REJI7sVIlFPnugvs6WAK5E4v+TNEfiaFcuEtbRZUgcUB5r3vnq2L96W5qVSPgqh5X3/y3RKy034NDTHx9nfR+RKf8jo0UAfl3O9U3JlRIjspCLKi7jt1ExlLM4i2a9jSLSKO62GJUBOfj5VH02YH7cZTEqk3LeAmBTFtT1RyT8czFiVI5lre41jgZwmhoFmiBxB0oTAMcjcVi2HhL/+jtj2x0A25A4qb9ZN/brjc8qAAtC7seJEePIU86IxoJqSESVeMqah0SsqHezmP0NJK7EKHJ87zUUsRAJQ09J3B0xYvyM/wF81Xv+eS0KngAAAABJRU5ErkJggg==' alt='Logo' style='width:231px;'>
    </div>
    <div class='container'>
        <!-- Upload Button -->
        <div id='uploadSection'>
            <button onclick="document.getElementById('fileInput').click();">Select File</button>
            <input type='file' id='fileInput' class='hidden' accept='.bin' onchange='uploadFile(this.files)'>
        </div>
        
        <!-- Progress Section -->
        <div id='progressSection' class='hidden'>
            <p id='progressTitle'>Uploading...</p>
            <div style='width: 80%; margin: 0 auto; background: #555; border-radius: 5px;'>
                <div id='progressBar'></div>
            </div>
            <p id='progressPercent'>0%</p>
        </div>
        
        <!-- Success Section -->
        <div id='successSection' class='hidden'>
            <p>Update Successful</p>
            <button onclick='resetView()'>Go Back</button>
        </div>
        
        <!-- Error Section -->
        <div id='errorSection' class='hidden'>
            <p id='errorTitle'>Error</p>
            <p id='errorReason'>An unexpected error occurred.</p>
            <button onclick='resetView()'>Go Back</button>
        </div>
    </div>
    
    <script>
        function uploadFile(files) {
            if (!files || files.length !== 1 || !files[0].name.endsWith('.bin')) {
                alert('Please select a valid .bin file.');
                return;
            }
            const file = files[0];
            document.getElementById('uploadSection').classList.add('hidden');
            document.getElementById('progressSection').classList.remove('hidden');
            
            const xhr = new XMLHttpRequest();
            xhr.open('POST', '/ota/upload', true);
            xhr.upload.onprogress = function(e) {
                if (e.lengthComputable) {
                    const percent = Math.round((e.loaded / e.total) * 100);
                    document.getElementById('progressBar').style.width = percent + '%';
                    document.getElementById('progressPercent').textContent = percent + '%';
                }
            };
            xhr.onload = function() {
                if (xhr.status === 200) {
                    document.getElementById('progressSection').classList.add('hidden');
                    document.getElementById('successSection').classList.remove('hidden');
                } else {
                    showError('Upload failed', xhr.responseText || 'Unknown error');
                }
            };
            xhr.onerror = function() {
                showError('Upload failed', 'Network error');
            };
            
            const formData = new FormData();
            formData.append('file', file);
            xhr.send(formData);
        }
        
        function showError(title, reason) {
            document.getElementById('progressSection').classList.add('hidden');
            document.getElementById('errorSection').classList.remove('hidden');
            document.getElementById('errorTitle').textContent = title;
            document.getElementById('errorReason').textContent = reason;
        }
        
        function resetView() {
            document.getElementById('uploadSection').classList.remove('hidden');
            document.getElementById('progressSection').classList.add('hidden');
            document.getElementById('successSection').classList.add('hidden');
            document.getElementById('errorSection').classList.add('hidden');
            document.getElementById('progressBar').style.width = '0%';
            document.getElementById('progressPercent').textContent = '0%';
        }
    </script>
</body>
</html>
)rawliteral";

#endif
