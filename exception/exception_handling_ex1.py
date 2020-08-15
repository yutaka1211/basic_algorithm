def calc_tri(base, height):
    return base * height * 0.5

base = 10
height = '5'

try:                                #エラーが起きる可能性のある箇所
    result = calc_tri(base, height)
    print(result)
except Exception as e:              #エラーが生じた場合
    print('エラーでござ')
    print(e)                        #エラーの内容が表示される